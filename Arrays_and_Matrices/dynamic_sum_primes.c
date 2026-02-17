#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    if (n <= 1)
     return 0; 
    if (n <= 3) 
    return 1;  
    if (n % 2 == 0 || n % 3 == 0) 
    return 0;  
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) 
        return 0;  
    }
    return 1;  
}

int sumPrimes(int* arr, int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int a;
    printf("Enter the number of elements: ");
    scanf("%d", &a);
    int* arr = (int*)malloc(a * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter %d elements:\n", a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
    int primeSum = sumPrimes(arr, a);
    printf("Sum of prime elements: %d\n", primeSum);

    free(arr);

    return 0;
}
