#include <stdio.h>
typedef struct {
    float real;
    float imaginary;
} Complex;
Complex addComplex(Complex a, Complex b);
void multiplyComplex(Complex* a, Complex* b, Complex* result);
void displayComplex(Complex c);

int main() {
    int choice;
    Complex num1, num2, result;

    do {
        printf("Menu:\n");
        printf("1. Add two complex numbers\n");
        printf("2. Multiply two complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter real and imaginary parts of 1st complex number:\n");
                scanf("%f %f", &num1.real, &num1.imaginary);
                printf("Enter real and imaginary parts of 2nd complex number:\n");
                scanf("%f %f", &num2.real, &num2.imaginary);
                result = addComplex(num1, num2);
                printf("Sum: ");
                displayComplex(result);
                break;

            case 2:
                printf("Enter real and imaginary parts of 1st complex number:\n");
                scanf("%f %f", &num1.real, &num1.imaginary);
                printf("Enter real and imaginary parts of 2nd complex number:\n");
                scanf("%f %f", &num2.real, &num2.imaginary);
                multiplyComplex(&num1, &num2, &result);
                printf("Product: ");
                displayComplex(result);
                break;

            case 3:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice. Enter again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}
Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}
void multiplyComplex(Complex* a, Complex* b, Complex* result) {
    result->real = (a->real * b->real) - (a->imaginary * b->imaginary);
    result->imaginary = (a->real * b->imaginary) + (a->imaginary * b->real);
}
void displayComplex(Complex c) {
    if (c.imaginary >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imaginary);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imaginary);
    }
}

