#include <stdio.h>

// Function to check if a matrix is symmetric
int isSymmetric(int matrix[][10], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Matrix is not symmetric
            }
        }
    }
    return 1; // Matrix is symmetric
}

// Function to print a matrix
void printMatrix(int matrix[][10], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[10][10];
    int size, i, j;

    // Get the size of the matrix from the user
    printf("Enter the size of the matrix (max 10): ");
    scanf("%d", &size);

    // Get the matrix elements from the user
    printf("Enter the matrix elements:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    printMatrix(matrix, size);

    // Check if the matrix is symmetric
    if (isSymmetric(matrix, size)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}