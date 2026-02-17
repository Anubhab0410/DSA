#include <stdio.h>

#define MAX_DEGREE 10

int main() {
    int poly1[MAX_DEGREE + 1] = {0};
    int poly2[MAX_DEGREE + 1] = {0};
    int result[2 * MAX_DEGREE + 1] = {0}; 
    int degree2,degree1;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);

    printf("Enter the coefficients for the first polynomial (highest degree first):\n");
    for (int i = degree1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);

    printf("Enter the coefficients for the second polynomial (highest degree first):\n");
    for (int i = degree2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
    printf("First polynomial: ");
    int firstTerm = 1; 
    for (int i = degree1; i >= 0; i--) {
        if (poly1[i] != 0) {
            if (!firstTerm && poly1[i] > 0) {
                printf(" + ");
            }
            if (i == 0 || poly1[i] != 1 && poly1[i] != -1) {
                printf("%d", poly1[i]);
            } else if (poly1[i] == -1) {
                printf("-");
            }
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
            firstTerm = 0;
        }
    }
    printf("\n");
    printf("Second polynomial: ");
    firstTerm = 1; 
    for (int i = degree2; i >= 0; i--) {
        if (poly2[i] != 0) {
            if (!firstTerm && poly2[i] > 0) {
                printf(" + ");
            }
            if (i == 0 || poly2[i] != 1 && poly2[i] != -1) {
                printf("%d", poly2[i]);
            } else if (poly2[i] == -1) {
                printf("-");
            }
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
            firstTerm = 0;
        }
    }
    printf("\n");
    int maxDegree = degree1 + degree2;
    printf("Product of polynomials: ");
    firstTerm = 1; 
    for (int i = maxDegree; i >= 0; i--) {
        if (result[i] != 0) {
            if (!firstTerm && result[i] > 0) {
                printf(" + ");
            }
            if (i == 0 || result[i] != 1 && result[i] != -1) {
                printf("%d", result[i]);
            } else if (result[i] == -1) {
                printf("-");
            }
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
            firstTerm = 0; 
        }
    }
    printf("\n");

    return 0;
}
