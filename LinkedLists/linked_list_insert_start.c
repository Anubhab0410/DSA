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
void insertStart(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;  
    *head = newNode;        }

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
    int num,data;
    printf("Enter the no of nodes to insert\n");
    scanf("%d",&num);
    for (int i=0;i<num;i++){
    printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertStart(&head, data);
    } 
    printf("THe linked list is:");
    printList(head);

    return 0;
}
