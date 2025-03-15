#include<stdio.h>
typedef struct term{
	int c;
	int e;
}term;

typedef struct poly{
	int n;
	term* t;
}poly;

void init(poly* p, int size);
void append(poly* p, int c, int e);
void display(poly* p);
void add_poly(poly* p, poly* q, poly* result);
void sub_poly(poly* p, poly* q, poly* result);
