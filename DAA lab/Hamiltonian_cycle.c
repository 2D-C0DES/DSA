#include <stdio.h>
#include <stdbool.h>

#define V 20 // Max number of vertices (can increase as needed)

// Function to print the Hamiltonian cycle
void printSolution(int path[], int n) {
    printf("Hamiltonian Cycle exists:\nPath: ");
    for (int i = 0; i < n; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]); // complete the cycle
}

// Check if the current vertex can be added to path
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if current vertex is adjacent to previous vertex
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if the vertex is already in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive utility to solve Hamiltonian Cycle problem
bool hamiltonianUtil(bool graph[V][V], int path[], int pos, int totalVertices) {
    if (pos == totalVertices) {
        // If there is an edge from the last to the first vertex
        return graph[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < totalVertices; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1, totalVertices))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Main function to solve the problem
bool hamiltonianCycle(bool graph[V][V], int totalVertices) {
    int path[V];
    for (int i = 0; i < totalVertices; i++)
        path[i] = -1;

    // Start at vertex 0
    path[0] = 0;

    if (hamiltonianUtil(graph, path, 1, totalVertices) == false) {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }

    printSolution(path, totalVertices);
    return true;
}

int main() {
    int n, e;
    bool graph[V][V] = {false};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter %d edges (u v) (0-based indexing):\n", e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = true;
        graph[v][u] = true; // undirected graph
    }

    hamiltonianCycle(graph, n);
    return 0;
}
