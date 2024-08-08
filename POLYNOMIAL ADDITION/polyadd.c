#include <stdio.h>

#define MAX 100

// Function to input a polynomial
void inputPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

// Function to display a polynomial
void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i > 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int degree;

    // Input the degree of the polynomials
    printf("Enter the degree of the polynomials: ");
    scanf("%d", &degree);

    int poly1[MAX] = {0}, poly2[MAX] = {0}, result[MAX] = {0};

    // Input the first polynomial
    printf("Input the first polynomial:\n");
    inputPolynomial(poly1, degree);

    // Input the second polynomial
    printf("Input the second polynomial:\n");
    inputPolynomial(poly2, degree);

    // Add the two polynomials
    addPolynomials(poly1, poly2, result, degree);

    // Display the result
    printf("Resultant Polynomial after Addition: ");
    displayPolynomial(result, degree);

    return 0;
}
