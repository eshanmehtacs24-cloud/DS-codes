#include <stdio.h>
#include <stdlib.h>

/* Node structure for adjacency list */
struct node {
    int vertex;
    struct node* next;
};

struct node* adjList[20];
int visited[20];
int n;

/* Create a new node */
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Add edge (undirected graph) */
void addEdge(int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

/* DFS function */
void DFS(int v) {
    struct node* temp;
    visited[v] = 1;

    temp = adjList[v];
    while (temp != NULL) {
        if (visited[temp->vertex] == 0) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int i, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* Initialize adjacency list and visited array */
    for (i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    /* Start DFS from vertex 0 */
    DFS(0);

    /* Check if all vertices are visited */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("\nThe graph is NOT connected.\n");
            return 0;
        }
    }

    printf("\nThe graph is CONNECTED.\n");
    return 0;
}
