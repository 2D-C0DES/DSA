#include <stdio.h>

void printBoundaryElements(int matrix[][10], int rows, int cols) {
    // Print first row
    for (int i = 0; i < cols; i++) {
        printf("%d ", matrix[0][i]);
    }
    printf("\n");

    // Print last row
    for (int i = 0; i < cols; i++) {
        printf("%d ", matrix[rows - 1][i]);
    }
    printf("\n");

    // Print first and last columns (excluding first and last rows)
    for (int i = 1; i < rows - 1; i++) {
        printf("%d %d\n", matrix[i][0], matrix[i][cols - 1]);
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[10][10]; // Assuming max size of 10x10
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Boundary elements of the matrix:\n");
    printBoundaryElements(matrix, rows, cols);

    return 0;
}