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

// Stack structure
struct Stack {
    int* items;
    int top;
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
}

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->items = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

// Iterative DFS function using a stack
void DFSIterative(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    struct Stack* stack = createStack(graph->vertices);
    push(stack, startVertex);

    printf("DFS Traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = true;
        }

        struct Node* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjacentVertex = temp->data;
            if (!visited[adjacentVertex]) {
                push(stack, adjacentVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(stack->items);
    free(stack);
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    DFSIterative(graph, 0);

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        struct Node* current = graph->array[i].head;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}

