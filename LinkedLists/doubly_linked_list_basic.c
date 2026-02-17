#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtPosition(struct Node** head,int data,int pos)
{
    struct Node* newNode = createNode(data);
    if (*head==NULL)
    {
        *head=newNode;
        return;
    }
    struct Node* temp= *head;
    if (pos==1){
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next=newNode;
}
void deleteFromPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;

    if (pos == 1) { 
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Out of bounds\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}    
int main() {
    struct Node* head = NULL;
    int choice, data, pos;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert an element at a specific pos\n");
        printf("2. Delete an element from a specific pos\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the pos to insert the element: ");
                scanf("%d", &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 2:
                printf("Enter the pos to delete the element from: ");
                scanf("%d", &pos);
                deleteFromPosition(&head, pos);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
