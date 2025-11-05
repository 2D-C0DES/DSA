#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // For undirected graph, add the reverse edge
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}


int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency list and visited array
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
