#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000

int dist[MAX];       // Stores the shortest distances
int visited[MAX];    // Tracks visited vertices
int parent[MAX];     // Tracks the shortest path tree

// Find the vertex with minimum distance not yet visited
int findMinVertex(int n) {
    int min = INF, vertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            vertex = i;
        }
    }
    return vertex;
}

// Recursive function mimicking divide-and-conquer logic
void dijkstraDC(int graph[MAX][MAX], int n) {
    int u = findMinVertex(n);
    if (u == -1) return; // All reachable vertices visited

    visited[u] = 1;

    // Update distances of adjacent vertices
    for (int v = 0; v < n; v++) {
        if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
            parent[v] = u;
        }
    }

    // Recurse (conquer next minimum)
    dijkstraDC(graph, n);
}

// Function to print path from source to a vertex
void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    printPath(parent[v]);
    printf(" -> %d", v);
}

int main() {
    int graph[MAX][MAX], n, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialization
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[source] = 0;

    // Start recursive Dijkstra
    dijkstraDC(graph, n);

    // Output results
    printf("\nVertex\tDistance from Source\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i, dist[i]);
        printPath(i);
        printf("\n");
    }

    return 0;
}
