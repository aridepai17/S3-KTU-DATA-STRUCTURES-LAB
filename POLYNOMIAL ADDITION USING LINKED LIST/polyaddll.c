#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial node
typedef struct Node {
    int coef; // Coefficient
    int exp;  // Exponent
    struct Node *next;
} Node;

// Function to create a new polynomial node
Node* createNode(int coef, int exp) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the polynomial linked list
void insertNode(Node **head, int coef, int exp) {
    Node *newNode = createNode(coef, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        if (temp->exp == exp) {
            temp->coef += coef;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to add two polynomials
Node* addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sumCoef = poly1->coef + poly2->coef;
            if (sumCoef != 0) {
                insertNode(&result, sumCoef, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(Node *head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        if (temp->coef > 0 && temp != head) {
            printf(" + ");
        }
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int coef, exp, n, i;

    // Input first polynomial
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient exponent) for the first polynomial:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insertNode(&poly1, coef, exp);
    }

    // Input second polynomial
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient exponent) for the second polynomial:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insertNode(&poly2, coef, exp);
    }

    // Add the polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    // Free allocated memory (optional)
    Node *temp;
    while (poly1 != NULL) {
        temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
