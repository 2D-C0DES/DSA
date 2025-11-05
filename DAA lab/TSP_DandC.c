#include <stdio.h>
#include <limits.h>

#define MAX 10

int minCost = INT_MAX;
int finalPath[MAX];   // Stores the final minimum cost path
int tempPath[MAX];    // Temporary path to test during recursion

// Recursive function for TSP
void tsp(int graph[MAX][MAX], int visited[MAX], int currPos, int n, int count, int cost, int start) {
    // Base case: All cities visited, return to start
    if (count == n && graph[currPos][start]) {
        int totalCost = cost + graph[currPos][start];

        // Check if this path is better than the previous best
        if (totalCost < minCost) {
            minCost = totalCost;

            // Store the current path into finalPath
            for (int i = 0; i < n; i++)
                finalPath[i] = tempPath[i];
            finalPath[n] = start; // Complete the cycle by returning to start
        }
        return;
    }

    // Try all unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = 1;
            tempPath[count] = i;  // Store current city in temp path

            tsp(graph, visited, i, n, count + 1, cost + graph[currPos][i], start);

            visited[i] = 0; // Backtrack
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int n;

    // Input number of cities
    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Input distance matrix
    printf("Enter distance matrix (0 if no direct path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Initialize visited and path
    visited[0] = 1;
    tempPath[0] = 0;

    tsp(graph, visited, 0, n, 1, 0, 0);

    // Output the results
    printf("\nMinimum Cost: %d\n", minCost);
    printf("Path Taken: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", finalPath[i]);
    }
    printf("\n");

    return 0;
}
