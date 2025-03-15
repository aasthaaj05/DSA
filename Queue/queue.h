typedef struct data {
    char name[16];
    unsigned int age;
}data;

typedef struct node{
	data d;
	struct node* next;
}Node;

typedef struct queue{
	Node* head;
	Node* tail;
}queue;

//qinit, enq, deq, qfull, qempty
void qinit(queue* q);
void enq(queue* q, data d);
data deq(queue* q);
int qfull(queue* q);
int qempty(queue* q);
