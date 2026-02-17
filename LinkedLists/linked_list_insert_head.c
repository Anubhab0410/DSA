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
void insertStart(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;  
    *headRef = newNode;        
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = NULL; 
    int numNodes, data;
    printf("Enter the number of nodes in the existing linked list: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertStart(&head, data);
    }
    printf("The existing linked list is: ");
    printList(head);
    printf("Enter the data for the new node to be inserted at the beginning: ");
    scanf("%d", &data);
    insertStart(&head, data);
    printf("The updated linked list is: ");
    printList(head);

    return 0;
}
