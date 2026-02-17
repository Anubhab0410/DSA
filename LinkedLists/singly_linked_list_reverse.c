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
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;
    }
    *head = prev;  
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
    int numNodes, data;
    printf("Enter the number of nodes in the LL: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("The LL before reversal ");
    traverseList(head);
    reverseList(&head);
    printf("Updated LL is: ");
    traverseList(head);   
     freeList(head);
    return 0;
}
