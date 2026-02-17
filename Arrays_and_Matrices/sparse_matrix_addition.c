#include <stdio.h>

#define MAX_TERMS 100

int main() {
    int sparseMatrix1[MAX_TERMS][3]; 
    int sparseMatrix2[MAX_TERMS][3]; 
    int result[MAX_TERMS][3];    
    int numTerms1, numTerms2;
    int i,j,k=0;
    printf("Enter the number of non-zero terms in the first matrix: ");
    scanf("%d", &numTerms1);

    printf("Enter the non-zero terms of the first matrix (row column value):\n");
    for (i = 0; i < numTerms1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d %d", &sparseMatrix1[i][0], &sparseMatrix1[i][1], &sparseMatrix1[i][2]);
    }
    printf("Enter the number of non-zero terms in the second matrix: ");
    scanf("%d", &numTerms2);

    printf("Enter the non-zero terms of the second matrix (row column value):\n");
    for (i = 0; i < numTerms2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d %d", &sparseMatrix2[i][0], &sparseMatrix2[i][1], &sparseMatrix2[i][2]);
    }
    int index1 = 0, index2 = 0;
    while (index1 < numTerms1 && index2 < numTerms2) {
        if (sparseMatrix1[index1][0] < sparseMatrix2[index2][0] || 
            (sparseMatrix1[index1][0] == sparseMatrix2[index2][0] && sparseMatrix1[index1][1] < sparseMatrix2[index2][1])) {
            result[k][0] = sparseMatrix1[index1][0];
            result[k][1] = sparseMatrix1[index1][1];
            result[k][2] = sparseMatrix1[index1][2];
            index1++;
        } else if (sparseMatrix1[index1][0] > sparseMatrix2[index2][0] || 
                   (sparseMatrix1[index1][0] == sparseMatrix2[index2][0] && sparseMatrix1[index1][1] > sparseMatrix2[index2][1])) {
            result[k][0] = sparseMatrix2[index2][0];
            result[k][1] = sparseMatrix2[index2][1];
            result[k][2] = sparseMatrix2[index2][2];
            index2++;
        } else {
            result[k][0] = sparseMatrix1[index1][0];
            result[k][1] = sparseMatrix1[index1][1];
            result[k][2] = sparseMatrix1[index1][2] + sparseMatrix2[index2][2];
            index1++;
            index2++;
        }
        k++;
    }
    while (index1 < numTerms1) {
        result[k][0] = sparseMatrix1[index1][0];
        result[k][1] = sparseMatrix1[index1][1];
        result[k][2] = sparseMatrix1[index1][2];
        index1++;
        k++;
    }
    while (index2 < numTerms2) {
        result[k][0] = sparseMatrix2[index2][0];
        result[k][1] = sparseMatrix2[index2][1];
        result[k][2] = sparseMatrix2[index2][2];
        index2++;
        k++;
    }
    printf("Resultant sparse matrix after addition:\n");
    printf("Row Column Value\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}




   