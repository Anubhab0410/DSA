#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Stack structure using an array
typedef struct Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the top element in the stack
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1; // Initialize the top of the stack to -1 (empty stack)
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1;
    }
    int popped = stack->arr[stack->top--];
    printf("%d popped from the stack.\n", popped);
    return popped;
}

// Function to traverse and display elements of the stack
void traverse(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    printf("Top element is %d\n", stack->arr[stack->top]);
    return stack->arr[stack->top];
}

// Main function to test the stack operations
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
