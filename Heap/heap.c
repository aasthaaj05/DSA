#include<stdio.h>
#include"heap.h"
#include<stdlib.h>

void init(Heap* h, int size){
	h->rear=-1;
	h->size=size;
	h->A=(int*)malloc(sizeof(int)*size);
}

void swap(Heap* h, int a, int b){
	if(a>=h->size||b>=h->size) return;
	int temp=h->A[a];
	h->A[a]=h->A[b];
	h->A[b]=temp;
}

int parent(int ind){
	return (ind-1)/2;
}

void printHeap(Heap* h){
	for(int i=0;i<=h->rear;i++)
		printf("%d ", h->A[i]);
	printf("\n");
}

void insert(Heap* h, int value) {
    if (h->rear == h->size - 1) return;
    h->A[++h->rear] = value;
    int i = h->rear;
    while (i > 0 && h->A[parent(i)] < h->A[i]) {
        swap(h, i, parent(i));
        i = parent(i);
    }
}

void heapify(Heap* h1){
    if(h1->rear==0 || h1->rear==-1)
        return;
    int j=0;
    while(j <=(h1->rear)){
        int lchild=2*j+1;
        int rchild=2*j+2;
        
        //end of heap, no such child exists
        if(lchild > h1->rear)
            return;
            
        //if only lchild exists
        if(rchild > h1->rear){
            if(h1->A[j] < h1->A[lchild]){
                swap(h1, j, lchild);
            }
            return;
        }
        
        //if both children exist
        if((h1->A[j] > h1->A[lchild]) && (h1->A[j] > h1->A[rchild]))
            return;
            
        if(h1->A[lchild] > h1->A[rchild]){
            swap(h1, j, lchild);
            j=lchild;
        }else{
            swap(h1, j, rchild);
            j=rchild;
        }
    }
}
	
void heap_sort(Heap* h){
	if(h->rear<=0) return;
	int k=h->rear;
	for(int i=h->rear;i>0;i--){
		swap(h, i, 0);
		h->rear--;
		heapify(h);
	}
	h->rear=k;
}

void readFileToHeap(Heap* h, const char* filename) { 
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        insert(h, num);
    }
    fclose(file);
}
