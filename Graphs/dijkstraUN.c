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
            graph->G[i][j] = (i == j) ? 0 : INF; // Distance from a vertex to itself is 0, else INF
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
        graph->G[dest][src] = cost; // If the graph is undirected, comment this line if need directeed
    }
}

// Function to find the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree
int minDistance(int minDist[], int visited[], int n) {
    int min = INF, minIndex;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && minDist[i] < min) {
            min = minDist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm to find the shortest path from a start vertex
void dijkstra(struct Graph* graph, int start) {
    int minDist[MAX];      // minDist[i] will hold the shortest distance from start to i
    int visited[MAX] = {0}; // visited[i] will be 1 if vertex i is included in the shortest path tree

    // Initialize distances to all vertices as infinite and visited[] as false
    for (int i = 0; i < graph->n; i++) {
        minDist[i] = INF;
    }
    minDist[start] = 0; // Distance from start to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < graph->n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(minDist, visited, graph->n);
        visited[u] = 1; // Mark the picked vertex as processed

        // Update minDist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->n; v++) {
            // Update minDist[v] only if it is not in visited, there is an edge from u to v, 
            // and total weight of path from start to v through u is smaller than current value of minDist[v]
            if (!visited[v] && graph->G[u][v] != INF && minDist[u] + graph->G[u][v] < minDist[v]) {
                minDist[v] = minDist[u] + graph->G[u][v];
            }
        }
    }

    // Print the calculated shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < graph->n; i++) {
        printf("%d \t\t %d\n", i, minDist[i]);
    }
}

int main() {
    struct Graph g;
    accept(&g);

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(&g, start);
    return 0;
}

