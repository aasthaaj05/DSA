/*
Create a hash table with chaining for collision handling. Use linked
lists to store multiple values at the same hash index.
o Experiment: Insert a series of integer keys into your hash table. Identify when
and where collisions occur, and observe how chaining handles them.
*/

#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 11

typedef struct Node{
	int val;
	struct Node* next;
}Node;

typedef struct Hash{
	Node* table[TABLE_SIZE];
}Hash;

void init(Hash* h){
	for(int i=0;i<TABLE_SIZE;i++){
		h->table[i]=NULL;
	}
}

int division(int key){
	return key%TABLE_SIZE;
}

void insert(Hash* h, int key){
	int ind=division(key);
	Node* nn=(Node*)malloc(sizeof(Node));
	nn->val=key;
	nn->next=h->table[ind];
	if (h->table[ind] != NULL) {
        	printf("Collision detected at index %d for key %d\n", ind, key);
        }
	h->table[ind]=nn;
}



void print(Hash* h){
	for(int i=0;i<TABLE_SIZE;i++){
		printf("%d \n", i);
		Node* temp=h->table[i];
		while(temp!=NULL){
			printf("%d ", temp->val);
			temp=temp->next;
		}
		printf("\n");
		printf("\n");
	}
}

void analyzeChains(Hash* ht) {
    int totalChains = 0;
    int totalLength = 0;
    int maxChainLength = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int chainLength = 0;
        Node* current = ht->table[i];
        while (current != NULL) {
            chainLength++;
            current = current->next;
        }
        if (chainLength > 0) totalChains++;
        totalLength += chainLength;
        if (chainLength > maxChainLength) maxChainLength = chainLength;
    }

    double averageChainLength = totalChains > 0 ? (double)totalLength / totalChains : 0.0;
    printf("Average chain length: %.2f\n", averageChainLength);
    printf("Maximum chain length: %d\n", maxChainLength);
}

int main() {
    Hash* ht=(Hash*)malloc(sizeof(Hash));
    init(ht);
    int keys[]={20, 19, 6, 10, 55, 44, 92, 36, 25};
    int size=sizeof(keys) / sizeof(keys[0]);
    for(int i=0;i<size;i++){
        insert(ht, keys[i]);
    }
    printf("Hash Table with Chaining:\n");
    print(ht);
    analyzeChains(ht);
}
