#include <stdio.h>

#define MAX 100

// Structure to represent a sparse matrix in a compressed format
typedef struct {
    int row;
    int col;
    int value;
} SparseElement;

// Function to input a sparse matrix
void inputSparseMatrix(SparseElement sparse[], int *numElements) {
    int rows, cols, value;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", numElements);

    printf("Enter the non-zero elements (row col value):\n");
    for (int i = 0; i < *numElements; i++) {
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(SparseElement sparse[], int numElements, int rows, int cols) {
    int matrix[MAX][MAX] = {0};
    for (int i = 0; i < numElements; i++) {
        matrix[sparse[i].row][sparse[i].col] = sparse[i].value;
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(SparseElement sparse[], SparseElement transposed[], int numElements) {
    for (int i = 0; i < numElements; i++) {
        transposed[i].row = sparse[i].col;
        transposed[i].col = sparse[i].row;
        transposed[i].value = sparse[i].value;
    }
}

// Function to add two sparse matrices
void addSparseMatrices(SparseElement sparse1[], int num1, SparseElement sparse2[], int num2, SparseElement result[], int *numResult) {
    int i = 0, j = 0, k = 0;

    while (i < num1 && j < num2) {
        if (sparse1[i].row < sparse2[j].row ||
            (sparse1[i].row == sparse2[j].row && sparse1[i].col < sparse2[j].col)) {
            result[k++] = sparse1[i++];
        } else if (sparse2[j].row < sparse1[i].row ||
                   (sparse2[j].row == sparse1[i].row && sparse2[j].col < sparse1[i].col)) {
            result[k++] = sparse2[j++];
        } else {
            if (sparse1[i].value + sparse2[j].value != 0) {
                result[k].row = sparse1[i].row;
                result[k].col = sparse1[i].col;
                result[k++].value = sparse1[i++].value + sparse2[j++].value;
            } else {
                i++;
                j++;
            }
        }
    }

    while (i < num1) {
        result[k++] = sparse1[i++];
    }

    while (j < num2) {
        result[k++] = sparse2[j++];
    }

    *numResult = k;
}

int main() {
    SparseElement sparse1[MAX], sparse2[MAX], result[MAX], transposed[MAX];
    int num1, num2, numResult;

    // Input the first sparse matrix
    printf("Input the first sparse matrix:\n");
    inputSparseMatrix(sparse1, &num1);

    // Input the second sparse matrix
    printf("Input the second sparse matrix:\n");
    inputSparseMatrix(sparse2, &num2);

    // Display the first sparse matrix
    printf("First Sparse Matrix:\n");
    displaySparseMatrix(sparse1, num1, 4, 4); // Assuming 4x4 matrix

    // Display the second sparse matrix
    printf("Second Sparse Matrix:\n");
    displaySparseMatrix(sparse2, num2, 4, 4); // Assuming 4x4 matrix

    // Transpose the first sparse matrix
    transposeSparseMatrix(sparse1, transposed, num1);
    printf("Transposed First Sparse Matrix:\n");
    displaySparseMatrix(transposed, num1, 4, 4); // Assuming 4x4 matrix

    // Add the two sparse matrices
    addSparseMatrices(sparse1, num1, sparse2, num2, result, &numResult);
    printf("Resultant Sparse Matrix after Addition:\n");
    displaySparseMatrix(result, numResult, 4, 4); // Assuming 4x4 matrix

    return 0;
}
