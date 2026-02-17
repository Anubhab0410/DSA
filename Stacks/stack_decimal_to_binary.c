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
    return popped;
}
void decimalToBinary(int decimal) {
    Stack stack;
    initStack(&stack);  
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }
    printf("Binary: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}
int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal); 

    return 0;
}
