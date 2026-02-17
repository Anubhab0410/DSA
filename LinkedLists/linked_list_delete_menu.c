#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* NEW = (Node*)malloc(sizeof(Node));
    if (NEW == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    NEW->data = data;
    NEW->next = NULL;
    return NEW;
}
void insertAtEnd(Node** head, int data) {
    Node* NEW = createNode(data);
    if (*head == NULL) {
        *head = NEW;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = NEW;
}
void deleteStart(Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (pos == 0) {
        deleteStart(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid\n");
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
void traverseList(Node* head) {
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
    int num, data, pos, choice;
    printf("Enter the no of nodes in the linked list: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("The linked list is: ");
    traverseList(head);
    printf("Choose :\n");
    printf("1. Delete at beginning\n");
    printf("2. Delete at end\n");
    printf("3. Delete at a specific pos\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            deleteStart(&head);
            break;
        case 2:
            deleteEnd(&head);
            break;
        case 3:
            printf("Enter the pos of the node to be deleted: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    printf("The updated linked list : ");
    traverseList(head);
    freeList(head);
    return 0;
}
