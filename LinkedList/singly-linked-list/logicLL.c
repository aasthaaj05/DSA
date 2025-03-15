#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "list.h"

void init(list *l){
	*l=NULL;
	return;
}

void append(list* l, int d){
	node* nn=(node*)malloc(sizeof(node));
	nn->data=d;
	nn->next=NULL;
	if(*l==NULL){
		*l=nn;
		return;
	}
	node*p=*l;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=nn;
}

int length(list *l){
	int count=0;
	node *p= *l;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}

void traverse(list head){
    node *p;
    p = head;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert_at_beg(list *l, int d){
	node* nn=(node*)malloc(sizeof(node));
	nn->data=d;
	nn->next=*l;
	*l=nn;
}

void remove_at_pos(list *l, int pos){
	if(*l==NULL){
		return;
	}
	if(pos==1){
		node* temp=*l;
		*l=(*l)->next;
		free(temp);
		return;
	}
	node* ptr=*l;
	int i=1;
	while(i<pos-1 && ptr!=NULL){
		ptr=ptr->next;
		i++;
	}
	node* ptr2=ptr->next;
	ptr->next=ptr2->next;
	free(ptr2);	
}
