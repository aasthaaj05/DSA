#include<stdio.h>

typedef struct array{
	int *A;
	int size;
	int len;
}array;

void init(array *a, int size);
void append(array *a, int ele);
int max(array *a);
void display(array *a);
void insert_at_index(array *a, int pos, int val);
void remove_at_index(array *a, int pos);
void reverse(array *a);
array* merge(array *a, array *b);
