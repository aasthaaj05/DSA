#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 999

struct Graph {
    int G[MAX][MAX];
    int n;
};

// Function to accept graph input
void accept(struct Graph* graph) {
    int i, j, e;
    int src, dest, cost;

    printf("Enter the number of vertices: ");
    scanf("%d", &graph->n);

    // Initialize the adjacency matrix
    for (i = 0; i < graph->n; i++) {
        for (j = 0; j < graph->n; j++) {
            graph->G[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter source vertex: ");
        scanf("%d", &src);
        printf("Enter destination vertex: ");
        scanf("%d", &dest);
        printf("Enter cost: ");
        scanf("%d", &cost);

        graph->G[src][dest] = cost;
        graph->G[dest][src] = cost;
    }
}

// Function to display the adjacency matrix
void display(struct Graph* graph) {
    int i, j;

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < graph->n; i++) {
        for (j = 0; j < graph->n; j++) {
            printf("%d\t", graph->G[i][j]);
        }
        printf("\n");
    }
}

// Optimized Prim's algorithm with O(n^2) complexity
void prims(struct Graph* graph) {
    int total = 0;
    int visited[MAX] = {0};
    int minEdge[MAX];
    int src, dest, count, i;

    // Initialize minEdge array with infinity
    for (i = 0; i < graph->n; i++) {
        minEdge[i] = INF;
    }

    // Select an arbitrary starting point, here 0
    visited[0] = 1;
    src = 0;
    count = 0;

    // Initialize minEdge with edges from src (vertex 0)
    for (i = 0; i < graph->n; i++) {
        if (graph->G[src][i] != 0) {
            minEdge[i] = graph->G[src][i];
        }
    }

    // Loop to find n-1 edges of MST
    while (count < graph->n - 1) {
        int min = INF;

        // Find the unvisited vertex with the smallest edge
        for (i = 0; i < graph->n; i++) {
            if (!visited[i] && minEdge[i] < min) {
                min = minEdge[i];
                dest = i;
            }
        }

        // Include the edge in the MST
        printf("Edge from %d to %d with cost %d\n", src, dest, min);
        total += min;
        visited[dest] = 1;
        src = dest;
        count++;

        // Update minEdge array with the new vertex
        for (i = 0; i < graph->n; i++) {
            if (!visited[i] && graph->G[dest][i] < minEdge[i] && graph->G[dest][i] != 0) {
                minEdge[i] = graph->G[dest][i];
            }
        }
    }

    printf("Total cost: %d\n", total);
}

void prims(const Graph *graph) {
    int total = 0;
    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    int *minEdge = (int *)malloc(graph->vertices * sizeof(int));
    int src, dest, count, i;

    // Initialize minEdge array with infinity
    for (i = 0; i < graph->vertices; i++) {
        minEdge[i] = INF;
    }

    // Select an arbitrary starting point, here 0
    visited[0] = 1;
    src = 0;
    count = 0;

    // Initialize minEdge with edges from src (vertex 0)
    for (i = 0; i < graph->vertices; i++) {
        if (graph->matrix[src][i] != 0) {
            minEdge[i] = graph->matrix[src][i];
        }
    }

    // Loop to find vertices - 1 edges of MST
    while (count < graph->vertices - 1) {
        int min = INF;

        // Find the unvisited vertex with the smallest edge
        for (i = 0; i < graph->vertices; i++) {
            if (!visited[i] && minEdge[i] < min) {
                min = minEdge[i];
                dest = i;
            }
        }

        // Include the edge in the MST
        printf("Edge from %d to %d with cost %d\n", src, dest, min);
        total += min;
        visited[dest] = 1;
        src = dest;
        count++;

        // Update minEdge array with the new vertex
        for (i = 0; i < graph->vertices; i++) {
            if (!visited[i] && graph->matrix[dest][i] < minEdge[i] && graph->matrix[dest][i] != 0) {
                minEdge[i] = graph->matrix[dest][i];
            }
        }
    }

    printf("Total cost: %d\n", total);

    free(visited);
    free(minEdge);
}

int main() {
    struct Graph g;
    accept(&g);
    display(&g);
    prims(&g);
    return 0;
}

