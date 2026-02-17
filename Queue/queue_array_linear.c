#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int isFull() {
    return rear == SIZE - 1;
}
int isEmpty() {
    return front == -1 || front > rear;
}
void enqueue() {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        int value;
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        if (front == -1) front = 0; 
        rear++;
        queue[rear] = value;
        printf("%d added to the queue.\n", value);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("%d removed from the queue.\n", queue[front]);
        front++;
        if (front > rear) {  
            front = rear = -1;
        }
    }
}
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}