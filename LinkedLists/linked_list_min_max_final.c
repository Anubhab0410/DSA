#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void LargestAndSmallest(struct Node* head, int* a, int* b) {
    *a = *b = head->data;
    struct Node* temp = head;
    
    while (temp != NULL) {
        if (temp->data > *a) {
            *a = temp->data;
        }
        if (temp->data < *b) {
            *b = temp->data;
        }
        temp = temp->next;
    }
}
int main() {
    struct Node* head = NULL;
    int n, value, a, b;
    printf("Enter the no of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }
    LargestAndSmallest(head, &a, &b);
    printf("Largest value: %d\n", a);
    printf("Smallest value: %d\n", b);
    return 0;
}
