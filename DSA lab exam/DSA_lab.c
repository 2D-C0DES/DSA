
#include <stdio.h>

void multiplyMatrices(int N, int P, int mat1[][N], int mat2[][P], int result[][P], int M) {

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int x, y;
    printf("Enter the number of rows in the first matrix: ");
    scanf("%d", &x);
    printf("Enter the number of columns in the first matrix: ");
    scanf("%d", &y);
    int a[x][y];

    int p, q;
    printf("Enter the number of rows in the second matrix: ");
    scanf("%d", &p);
    printf("Enter the number of columns in the second matrix: ");
    scanf("%d", &q);
    int b[p][q];

    if (y != p) {
        printf("Matrix multiplication is not possible. Columns of the first matrix must equal rows of the second matrix.\n");
        return 1;
    }

    printf("Enter the elements in the first matrix:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements in the second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    int result[x][q];
    multiplyMatrices(y, q, a, b, result, x);

    printf("The resulting matrix is:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
