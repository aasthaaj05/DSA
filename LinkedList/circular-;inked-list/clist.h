typedef struct node{
	int data;
	struct node* next;
}Node;

typedef Node* list;

int isEmpty(list l);
void init(list *head);
void traverse(list head);
int count(list l);
void append(list* l, int d);
void insert_at_beg(list *l, int data);
void insert_at_pos(list *l, int data, int pos);
void remove_beg(list *l);
void remove_end(list *l);
void remove_pos(list *l, int pos);
void sort(list* l);
