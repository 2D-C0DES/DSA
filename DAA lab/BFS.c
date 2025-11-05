#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    queue[++rear] = v;
    if (front == -1) front = 0;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to the adjacency list (undirected)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            temp = temp->next;
        }
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
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);
    printf("\n");

    return 0;
}
