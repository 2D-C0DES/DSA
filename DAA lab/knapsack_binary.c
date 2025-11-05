#include <stdio.h>

#define MAX_ITEMS 100  // Maximum number of items
#define MAX_CAPACITY 1000  // Maximum knapsack capacity

int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1], weight[MAX_ITEMS + 1], profit[MAX_ITEMS + 1], selected[MAX_ITEMS + 1];
int numItems, capacity;

// Function to compute the maximum profit using 0/1 Knapsack DP approach
void knapsack() {
    // Initialize the first row of the DP table with zero profit
    for (int i = 0; i <= capacity; i++)
        dp[0][i] = 0;

    // Filling the DP table
    for (int i = 1; i <= numItems; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (weight[i] <= j) { 
                // Check if including the current item gives a better profit
                if (dp[i - 1][j] > (profit[i] + dp[i - 1][j - weight[i]]))
                    dp[i][j] = dp[i - 1][j];  // Exclude current item
                else
                    dp[i][j] = profit[i] + dp[i - 1][j - weight[i]];  // Include current item
            } else {
                dp[i][j] = dp[i - 1][j];  // If weight exceeds, exclude item
            }
        }
    }
}

int main() {
    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &numItems);

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Input profits of items
    printf("Enter profits of items:\n");
    for (int i = 1; i <= numItems; i++)
        scanf("%d", &profit[i]);

    // Input weights of items
    printf("Enter weights of items:\n");
    for (int i = 1; i <= numItems; i++)
        scanf("%d", &weight[i]);

    // Compute maximum profit using knapsack function
    knapsack();

    // Print the DP table
    printf("Knapsack matrix:\n");
    for (int i = 0; i <= numItems; i++) {
        for (int j = 0; j <= capacity; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    // Print the maximum profit obtained
    printf("Maximum profit: %d\n", dp[numItems][capacity]);

    // Backtracking to find selected items
    for (int i = numItems, w = capacity; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) { 
            selected[i] = 1;  // Item is included in the optimal solution
            w -= weight[i];  // Reduce weight capacity
        } else {
            selected[i] = 0;  // Item is not included
        }
    }

    // Print selected items
    printf("Selected items: ");
    for (int i = 1; i <= numItems; i++)
        printf("%d ", selected[i]);
    printf("\n");

    return 0;
}
