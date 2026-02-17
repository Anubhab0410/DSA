#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;              
    struct Node* next;    
} Node;
typedef struct Stack {
    Node* top;            
} Stack;
void initStack(Stack* stack) {
    stack->top = NULL;     
}
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  
    if (newNode == NULL) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", data);
        return;
    }
    newNode->data = data;     
    newNode->next = stack->top; 
    stack->top = newNode;       
    printf("%d pushed onto the stack.\n", data);
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1;
    }
    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next; 
    free(temp); 
    printf("%d popped from the stack.\n", popped);
    return popped;
}
void traverse(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->next;     
    }
    printf("\n");
}
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    printf("Top element is %d\n", stack->top->data);
    return stack->top->data;
}
int main() {
    Stack stack;
    initStack(&stack);

    int choice, value;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                traverse(&stack);
                break;
            case 4:
                peek(&stack);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid operation.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
