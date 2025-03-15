#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int n, e;
    struct Edge edges[MAX];
};

// Find function for Union-Find
int find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]); // Path compression
    }
    return parent[i];
}

// Union function for Union-Find
void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);

    // Union by rank
    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Custom bubble sort to sort edges by weight
void bubbleSort(struct Edge edges[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges[j] and edges[j+1]
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Function to accept graph input
void accept(struct Graph* graph) {
    printf("Enter the number of vertices: ");
    scanf("%d", &graph->n);

    printf("Enter the number of edges: ");
    scanf("%d", &graph->e);

    for (int i = 0; i < graph->e; i++) {
        printf("Enter source, destination, and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(struct Graph* graph) {
    int parent[MAX], rank[MAX];
    struct Edge result[MAX]; // Stores the edges in the MST
    int mstWeight = 0;
    int mstEdges = 0;

    // Initialize parent and rank arrays
    for (int i = 0; i < graph->n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort all edges in increasing order of weight
    bubbleSort(graph->edges, graph->e);

    for (int i = 0; i < graph->e && mstEdges < graph->n - 1; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;

        // Check if adding this edge creates a cycle
        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            // If it doesn't create a cycle, include it in the MST
            result[mstEdges++] = graph->edges[i];
            mstWeight += weight;
            unionSets(parent, rank, setU, setV);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < mstEdges; i++) {
        printf("Edge from %d to %d with weight %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    struct Graph g;
    accept(&g);
    kruskalMST(&g);
    return 0;
}

