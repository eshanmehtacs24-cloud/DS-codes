#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct node *adj[20];
int visited[20], queue[20];
int n, front = 0, rear = -1, end;

struct node* createNode(int v)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

void bfs(int start)
{
    int v;
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        v = queue[front++];
        printf("%d ", v);

        if (v == end)
            return;

        struct node *temp = adj[v];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int i, e, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source and destination edges:\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);   // Directed graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("Enter ending vertex: ");
    scanf("%d", &end);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
