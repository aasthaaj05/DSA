/*
Implement a simple hash function using the division method.
Write a small program that hashes integers using your function, then observe how data is distributed across an array of a fixed size.
*/

#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 11

typedef struct item{
	int val,k;
}Item;

void init(Item* hashtable){
	for(int i=0;i<TABLE_SIZE;i++){
		hashtable[i].k=0;
		hashtable[i].val=i;
	}
}

int division(int key){
	return key%TABLE_SIZE;
}

void insert(Item* hashtable, int key){
	int ind=division(key);
	hashtable[ind].k++;
}

void print(Item* hashtable){
	for(int i=0;i<TABLE_SIZE;i++){
		printf("%d %d\n", hashtable[i].val, hashtable[i].k); 
	}
}

int main(){
	Item* hashtable=(Item*)malloc(TABLE_SIZE * sizeof(Item));
	init(hashtable);
	int numbers[] = {20, 50, 73, 19, 6, 77, 10, 55, 44, 92, 36, 25};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	for (int i = 0; i < size; i++) {
		insert(hashtable, numbers[i]);
	}
	print(hashtable);
}
