typedef struct node{
	int data;
	struct node* prev, *next;
}Node;

typedef struct DLL{
	Node* front;
	Node* rear;
}DLL;

void init(DLL* l);
int isEmpty(DLL l);
void append(DLL* l, int d);
int length(DLL l);
int search(DLL* l, int d);
void printLToR(DLL l);
void printRToL(DLL l);
void remove_pos(DLL* l, int pos);
void remove_beg(DLL* l);
void remove_end(DLL* l);
void insert_pos(DLL* l,int d, int pos);
void insert_beg(DLL* l, int d);
void sort(DLL* l);
void isPalindrome(DLL* l);
void removeDup(DLL* l);
