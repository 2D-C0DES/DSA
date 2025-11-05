#include <stdio.h>

void multiplyMatrices(int mat1[][10], int mat2[][10], int r1, int c1, int r2, int c2) {
    int res[r1][c2], i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Resultant Matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[10][10], mat2[10][10], r1, c1, r2, c2, i, j;
    printf("Enter rows and columns for matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for matrix 2: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Matrices cannot be multiplied.\n");
        return 1;
    }
    printf("Enter matrix 1 elements:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter matrix 2 elements:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    multiplyMatrices(mat1, mat2, r1, c1, r2, c2);
    return 0;
}