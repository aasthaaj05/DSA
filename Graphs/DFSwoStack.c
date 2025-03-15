#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the adjacency list
struct Node {
	int data;
	struct Node* next;
};

// Structure for the adjacency list
struct List {
	struct Node* head;
};

// Structure for the graph
struct Graph {
	int vertices;
	struct List* array;
};

// Function to create a new node
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->vertices = vertices;
	graph->array = (struct List*)malloc(vertices * sizeof(struct List));

	for (int i = 0; i < vertices; i++) {
		graph->array[i].head = NULL;
	}

	return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
	struct Node* newNode = createNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Uncomment the following code to make the graph undirected
	/*
	newNode = createNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
	*/
}

// Function to perform Depth First Search (DFS) from a given vertex
void DFS(struct Graph* graph, int vertex, bool visited[]) {
	visited[vertex] = true;
	printf("%d ", vertex);

	struct Node* currentNode = graph->array[vertex].head;
	while (currentNode) {
		int adjacentVertex = currentNode->data;
		if (!visited[adjacentVertex]) {
			DFS(graph, adjacentVertex, visited);
		}
		currentNode = currentNode->next;
	}
}

// Function to perform DFS traversal from a given vertex in a specified order
void DFSTraversal(struct Graph* graph, int* order, int orderSize) {
	bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
	for (int i = 0; i < graph->vertices; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < orderSize; i++) {
		if (!visited[order[i]]) {
			DFS(graph, order[i], visited);
		}
	}

	free(visited);
}

int main() {
	struct Graph* graph = NULL;
	int vertices, src, dest, choice;
	int* order = NULL;
	int orderSize;

	while (1) {
		printf("\nMenu:\n");
		printf("1. Create Graph\n");
		printf("2. Add Edge\n");
		printf("3. Perform DFS Traversal\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter the number of vertices: ");
				scanf("%d", &vertices);
				graph = createGraph(vertices);
				printf("Graph created with %d vertices.\n", vertices);
				break;

			case 2:
				if (graph == NULL) {
					printf("Graph not created. Please create a graph first.\n");
				} else {
					printf("Enter source and destination vertices for the edge: ");
					scanf("%d %d", &src, &dest);
					addEdge(graph, src, dest);
					printf("Edge added from %d to %d.\n", src, dest);
				}
				break;

			case 3:
				if (graph == NULL) {
					printf("Graph not created. Please create a graph first.\n");
				} else {
					orderSize = graph->vertices;
					order = (int*)malloc(orderSize * sizeof(int));
					printf("Enter the order of vertices for DFS traversal:\n");
					for (int i = 0; i < orderSize; i++) {
						printf("Vertex %d: ", i + 1);
						scanf("%d", &order[i]);
					}
					printf("DFS Traversal: ");
					DFSTraversal(graph, order, orderSize);
					printf("\n");
					free(order);
				}
				break;

			case 4:
				printf("Exiting...\n");
				// Free allocated memory
				if (graph != NULL) {
					for (int i = 0; i < graph->vertices; i++) {
						struct Node* current = graph->array[i].head;
						while (current != NULL) {
							struct Node* temp = current;
							current = current->next;
							free(temp);
						}
					}
					free(graph->array);
					free(graph);
				}
				exit(0);

			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
	return 0;
}

