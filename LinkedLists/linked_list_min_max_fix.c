#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* insertNode(int data){
    struct Node* NEW=(structNode*)malloc(sizeof(structNode));
    NEW->data = data;
    NEW->next = NULL;
    return NEW;
}
void insert(struct Node** head, int data) {
    struct Node* NEW = createNode(data);
    if (*head == NULL) {
        *head = NEW;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NEW;
    }
}
void LargestAndSmallest(struct Node* head, int* b, int* a) {
    *b = *a = head->data;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data > *b) {
            *b = temp->data;
        }
        if (temp->data < *a) {
            *a = temp->data;
        }
        temp = temp->next;
    }
}
int main() {
    struct Node* head = NULL;
    int n, value, b, a;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    findLargestAndSmallest(head, &b, &a);

    printf("Largest value: %d\n", b);
    printf("Smallest value: %d\n", a);

    return 0;
}