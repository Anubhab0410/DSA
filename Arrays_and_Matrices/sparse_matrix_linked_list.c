#include <stdio.h>
#include <stdlib.h>
struct Node {
    int row;         
    int col;          
    int value;        
    struct Node* next; 
};
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void displaySparseMatrix(struct Node* head) {
    if (head == NULL) {
        printf("The sparse matrix is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Sparse Matrix Representation (row, col, value):\n");
    while (temp != NULL) {
        printf("(%d, %d, %d)\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}
int main() {
    struct Node* head = NULL;
    int rows, cols, value;
    printf("Enter the no of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the no of columns in the matrix: ");
    scanf("%d", &cols);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at (%d, %d): ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                insertNode(&head, i, j, value);
            }
        }
    }
    displaySparseMatrix(head);
    return 0;
}
          
           
            
            
