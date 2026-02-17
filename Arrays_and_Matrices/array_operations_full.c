#include <stdio.h>

// Function prototypes
void insertElement(int arr[], int *n, int element, int position);
void deleteElement(int arr[], int *n, int position);
int linearSearch(int arr[], int n, int element);
void traverseArray(int arr[], int n);

int main() {
    int arr[100]; // Array to hold elements (assuming a maximum of 100 elements)
    int n = 0; // Current number of elements
    int choice, element, position, index;

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Insert element at specific position\n");
        printf("2. Delete element from specific position\n");
        printf("3. Linear search for an element\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert element
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", n);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Invalid position!\n");
                } else {
                    insertElement(arr, &n, element, position);
                }
                break;

            case 2:
                // Delete element
                printf("Enter the position (0 to %d): ", n-1);
                scanf("%d", &position);
                if (position < 0 || position >= n) {
                    printf("Invalid position!\n");
                } else {
                    deleteElement(arr, &n, position);
                }
                break;

            case 3:
                // Linear search
                printf("Enter the element to search for: ");
                scanf("%d", &element);
                index = linearSearch(arr, n, element);
                if (index != -1) {
                    printf("Element %d found at position %d.\n", element, index);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;

            case 4:
                // Traverse array
                printf("Array elements:\n");
                traverseArray(arr, n);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

// Function to insert an element at a specific position
void insertElement(int arr[], int *n, int element, int position) {
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *n, int position) {
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted from position %d.\n", position);
}

// Function to perform a linear search
int linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to traverse and display the array
void traverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
