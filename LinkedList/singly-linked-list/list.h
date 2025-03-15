typedef struct node{
	int data;
	struct node* next;
}node;

typedef node* list;

void init(list *head);
void traverse(list head);
void append(list* l, int d);
int length(list *l);
void insert_at_beg(list *l, int data);
void remove_at_pos(list *l, int pos);
