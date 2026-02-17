#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* NEW = (Node*)malloc(sizeof(Node));
    if (NEW == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    NEW->data = data;
    NEW->next = NULL;
    return NEW;
}
void insertAnypos(Node** headRef, int data, int pos) {
    Node* NEW = createNode(data);
    if (pos == 0) {
        NEW->next = *headRef;
        *headRef = NEW;
        return;
    }
    Node* temp = *headRef;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(NEW);
        return;
    }
    NEW->next = temp->next;
    temp->next = NEW;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    Node* head = NULL; 
    int num, data, pos;
    printf("Enter the number of nodes in the existing linked list: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAnypos(&head, data, i);  
    }
    printf("The existing linked list is: ");
    printList(head);
    printf("Enter the data for the new node to be inserted: ");
    scanf("%d", &data);
    printf("Enter the pos (0-based index) where the new node should be inserted: ");
    scanf("%d", &pos);
    insertAnypos(&head, data, pos);
    printf("The updated linked list is: ");
    printList(head);
    freeList(head);
    return 0;
}
