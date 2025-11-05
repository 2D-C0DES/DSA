#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

char board[MAX][MAX];
int n, count = 0;

void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int getCol(int row) {
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q') {
            return i;
        }
    }
    return INT_MAX;
}

int feasible(int row, int column) {
    for (int i = 0; i < row; i++) {  // Only need to check previous rows
        int queenCol = getCol(i);
        if (queenCol == column || abs(column - queenCol) == abs(row - i)) {
            return 0;  
        }
    }
    return 1;  
}

void NQueen(int row) {
    if (row < n) {
        for (int i = 0; i < n; i++) {
            if (feasible(row, i)) {
                board[row][i] = 'Q';  // Placing the queen
                NQueen(row + 1);      // Going to next row
                board[row][i] = '_';  // Backtrack when 
            }
        }
    } else {
        printf("Solution %d:\n", ++count);
        printBoard();
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    // Initialize board with '_'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '_';
        }
    }

    NQueen(0);  // Start placing from row 0

    if (count == 0) {
        printf("No solution exists for %d queens.\n", n);
    } else {
        printf("Total solutions found: %d\n", count);
    }

    return 0;
}
