#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"bfs.h"

void initQ(Queue* q, int size){
	q->front=-1;
	q->rear=-1;
	q->size=size;
	q->items=(int*)malloc(sizeof(int)*size);
}

void enqueue(Queue* q, int d){
	if(q->rear==q->size-1) return;
	if(isEmpty(q)){
		q->front=0;
	}
	q->items[++q->rear]=d;
}

int dequeue(Queue* q){
	if(isEmpty(q)) return INT_MIN;
	int result=q->items[q->front];
	if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
	}else{
		q->front++;
	}
	return result;	
}

int isEmpty(Queue* q){
	if(q->rear==-1) return 1;
	return 0;
}
void init(Graph* g, int v){
	g->v=v;
	g->adjList=(Node**)malloc(sizeof(Node*)*v);
	for(int i=0;i<g->v;i++){
		g->adjList[i]=NULL;
	}
}

Node* createNode(int d, int w){
	Node* nn=(Node*)malloc(sizeof(Node));
	nn->data=d;
	nn->wt=w;
	nn->next=NULL;
	return nn;
}

void addEdge(Graph* g, int s, int d, int w){
	Node* nn=createNode(d, w);
	nn->next=g->adjList[s];
	g->adjList[s]=nn;
	
	Node* nn2=createNode(s, w);
	nn2->next=g->adjList[d];
	g->adjList[d]=nn2;
}
void bfs(Graph* g, int start){
	int* visited=(int*)malloc(sizeof(int)*g->v);
	for(int i=0;i<g->v;i++){
		visited[i]=0;
	}
	visited[start]=1;
	Queue* q=(Queue*)malloc(sizeof(Queue));
	initQ(q,g->v);
	enqueue(q, start);
	while(isEmpty(q)!=1){
		int p=dequeue(q);
		printf("%d ", p);
		Node* temp=g->adjList[p];
		while(temp!=NULL){
			int adjVertex=temp->data;
			if(visited[adjVertex]!=1){
				visited[adjVertex]=1;
				enqueue(q, adjVertex);
			}
			temp=temp->next;
		}
		printf("\n");
	}
	free(visited);
	free(q->items);
}

void dfsUtil(Graph* g, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = g->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            dfsUtil(g, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph* g, int start) {
    int* visited = (int*)malloc(sizeof(int) * g->v);
    for (int i = 0; i < g->v; i++) {
        visited[i] = 0;
    }
    printf("DFS traversal: ");
    dfsUtil(g, start, visited);
    printf("\n");
    free(visited);
}

/*
typedef struct Stack {
    int size, top;
    int* items;
} Stack;

void initStack(Stack* s, int size) {
    s->size = size;
    s->top = -1;
    s->items = (int*)malloc(size * sizeof(int));
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int d) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = d;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Iterative DFS using a stack
void dfsIterative(Graph* g, int start) {
    int* visited = (int*)calloc(g->v, sizeof(int));  // Initialize visited array
    Stack stack;
    initStack(&stack, g->v);

    push(&stack, start);

    while (!isStackEmpty(&stack)) {
        int vertex = pop(&stack);

        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;
        }

        // Push all unvisited neighbors of the current vertex onto the stack
        for (int i = g->v - 1; i >= 0; i--) {  // Reverse order for proper traversal
            if (g->adjMatrix[vertex][i] != 0 && !visited[i]) {
                push(&stack, i);
            }
        }
    }

    free(visited);
    free(stack.items);
}
*/

void display(Graph* g) {
	for (int i = 0; i < g->v; i++) {
		printf("%d: ", i);
		Node* temp = g->adjList[i];
		while (temp != NULL) {
			printf("-> %d (weight %d) ", temp->data, temp->wt);
			temp = temp->next;
		}
		printf("\n");
	}
}
