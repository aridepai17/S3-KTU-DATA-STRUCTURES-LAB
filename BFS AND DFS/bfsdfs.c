#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Adjacency matrix for the graph
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n; // Number of vertices

// Function to initialize the adjacency matrix
void initializeGraph(int vertices) {
    n = vertices;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // For undirected graph
}

// BFS traversal
void BFS(int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFS(int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function to reset visited array
void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

int main() {
    int vertices, edges, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    resetVisited();
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    BFS(start);

    resetVisited();
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
