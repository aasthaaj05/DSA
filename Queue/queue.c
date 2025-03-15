#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

void qinit(queue* q) {
   	q->head = NULL;
	q->tail = NULL;
}

void enq(queue* q, data d){
	Node* nn=(Node*)malloc(sizeof(Node));
	nn->d=d;
	if(qempty(q)){
		nn->next=nn;
		q->head=nn;
		q->tail=nn;
		return;
	}
	//inserting nn at end of cLL
	nn->next=q->head;
	q->tail->next=nn;
	q->tail=nn;
}

data deq(queue* q) {
    data d={"",0};
    if(qempty(q)) return d;
    Node* temp = q->head;
    d = temp->d;
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next; 
        q->tail->next = q->head; 
    }

    free(temp);
    return d;
}

int qfull(queue* q){
	Node* temp=(Node*)malloc(sizeof(Node));
	if(temp==NULL) return 1;
	return 0;
}

int qempty(queue* q){
	if(q->head==NULL)return 1;
	return 0;
}
