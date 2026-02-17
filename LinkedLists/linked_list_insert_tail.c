#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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
    int numNodes, data;
    printf("Enter the number of nodes in the existing linked list: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("The existing linked list is: ");
    printList(head);
    printf("Enter the data for the new node to be inserted at the end: ");
    scanf("%d", &data);
    insertAtEnd(&head, data);
    printf("The updated linked list is: ");
    printList(head);
     return 0;
}
