#include <stdio.h>

int isSkewSymmetric(int matrix[][10], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] != -matrix[j][i]) {
                return 0; // Not skew symmetric
            }
        }
    }
    return 1; // Skew symmetric
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

    // Check if the matrix is skew symmetric
    if (isSkewSymmetric(matrix, size)) {
        printf("The matrix is skew symmetric.\n");
    } else {
        printf("The matrix is not skew symmetric.\n");
    }

    return 0;
}