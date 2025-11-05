#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the color assignments
void printSolution(int color[], int V) {
    printf("Color Assignments:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

// Check if the current color assignment is safe
bool isSafe(int v, bool graph[MAX][MAX], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

// Backtracking function to solve graph coloring
bool graphColoringUtil(bool graph[MAX][MAX], int m, int color[], int v, int V) {
    if (v == V)
        return true; // All vertices colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Main function to initialize data and start solving
bool graphColoring(bool graph[MAX][MAX], int m, int V) {
    int color[MAX] = {0}; // All colors initialized to 0

    if (graphColoringUtil(graph, m, color, 0, V) == false) {
        printf("Solution does not exist.\n");
        return false;
    }

    printSolution(color, V);
    return true;
}

int main() {
    int V, E, m;
    bool graph[MAX][MAX] = {false};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v) where 0 <= u,v < %d:\n", V);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = true;
        graph[v][u] = true; // Since undirected graph
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
