typedef struct Node{
	int data, wt;
	struct Node* next;
}Node;

typedef struct graph{
	int v;
	Node** adjList;
}Graph;

typedef struct Queue{
	int size, front, rear;
	int* items;
}Queue;

void initQ(Queue* q, int size);
void enqueue(Queue* q, int d);
int dequeue(Queue* q);
int isEmpty(Queue* q);
void init(Graph* g, int v);
Node* createNode(int d, int w);
void addEdge(Graph* g, int s, int d, int w);
void bfs(Graph* g, int start);
void display(Graph* g);
void dfsUtil(Graph* g, int vertex, int* visited);
void dfs(Graph* g, int start);
