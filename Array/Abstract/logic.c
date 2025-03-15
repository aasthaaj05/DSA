#include<stdio.h>
#include<stdlib.h>
#include "array.h"

void init(array *a, int size){
	a->A=(int *)malloc(size*sizeof(int));
	a->size=size;
	a->len=0;
	for (int i = 0; i < size; i++) {
		a->A[i] = rand() % 100; 
		a->len++;
	}
}

void append(array *a, int ele){
	if(a->len<a->size){
		a->A[a->len]=ele;
		a->len++;
	}
}

int max(array *a){
	int i, max=a->A[0];
	for(i=0;i<a->len;i++){
		if(max<=a->A[i]){
			max=a->A[i];
		}
	}
	return max;
}

void display(array *a){
	int i;
	for(i=0;i<a->len;i++){
		printf("%d ", a->A[i]);
	}
	printf("\n");
}

void insert_at_index(array* arr, int index, int x) {
    if (index >= 0 && index <= arr->len) {
       for (int i = arr->len; i > index; i--) {
           arr->A[i] = arr->A[i - 1];
       }
       arr->A[index] = x;
       arr->len++;
    }
}

void remove_at_index(array *a, int pos){
	if(pos>=0 && pos<a->len){
		int i;
		for(i=pos;i<a->len-1;i++){
			a->A[i]=a->A[i+1];
		}
		a->len--;
	}
}

void reverse(array *a){
	int i=0, j=a->len-1;
	while(i<j){
		int temp=a->A[i];
		a->A[i]=a->A[j];
		a->A[j]=temp;
		i++;
		j--;
	}
}

array* merge(array *a, array *b){
	array *c=(array *)malloc(sizeof(array));
	c->len=a->len + b->len;
	c->size=c->len;
	c->A = (int *)malloc(c->size * sizeof(int)); 
	int i;
	for(i=0;i<a->len;i++){
		c->A[i]=a->A[i];
	}
	for (int k = 0; k < b->len; k++) {
        c->A[i++] = b->A[k];
	 }

	return c;
}

