#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int V, E;
    Edge edge[MAX];
} Graph;

// Disjoint Set (Union-Find) functions
int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]); // Path compression
}

void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    parent[xroot] = yroot;
}

// Comparator for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// Kruskal’s algorithm
void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX]; // Store MST
    int e = 0;         // Index for result[]
    int i = 0;         // Index for sorted edges

    // Sort all the edges in increasing order of weight
    qsort(graph->edge, graph->E, sizeof(Edge), compareEdges);

    // Initialize disjoint sets
    for (int v = 0; v < V; v++)
        parent[v] = v;

    while (e < V - 1 && i < graph->E) {
        Edge next = graph->edge[i++];

        int x = find(next.src);
        int y = find(next.dest);

        if (x != y) {
            result[e++] = next;
            unionSets(x, y);
        }
    }

    // Print result
    int totalWeight = 0;
    printf("Edges in MST:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
}


int main() {
    Graph graph;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &graph.V, &graph.E);

    printf("Enter each edge in the format: source destination weight\n");
    for (int i = 0; i < graph.E; i++) {
        scanf("%d %d %d", &graph.edge[i].src, &graph.edge[i].dest, &graph.edge[i].weight);
    }

    kruskalMST(&graph);
    return 0;
}
