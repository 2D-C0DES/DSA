#include <stdio.h>

void printDiagonal(int matrix[][10], int size) {
    int i;
    printf("Diagonal Elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf(" ");
}

int main() {
    int matrix[10][10];
    int size, i, j;

    // Get the size of the matrix from the user
    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &size);

    // Get the matrix elements from the user
    printf("Enter the matrix elements:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the diagonal elements
    printDiagonal(matrix, size);

    return 0;
}