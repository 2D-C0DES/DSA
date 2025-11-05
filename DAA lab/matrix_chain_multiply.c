#include <stdio.h>
#include <limits.h>

#define MAX 100

int m[MAX][MAX], s[MAX][MAX], p[MAX];
int n;

void max_chain() {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) { // chain length
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void optimal(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        optimal(i, s[i][j]);
        optimal(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions (length %d):\n", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    max_chain();

    printf("\nCost Matrix:\n");
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
    if (i > j)
            printf("  ___ ");
        else
            printf(" %5d", m[i][j]);
    }
    printf("\n");
}

printf("\nSplit Matrix:\n");
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i >= j)
            printf("  ___ ");
        else
            printf(" %5d", s[i][j]);
    }
    printf("\n");  
}

    printf("\nMinimum multiplication cost: %d\n", m[1][n]);

    printf("\nOptimal Parenthesization: ");
    optimal(1, n);
    printf("\n");

    return 0;
}
