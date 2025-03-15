#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"doublyLL.h"

void init(DLL* l){
	l->rear=NULL;
	l->front=NULL;
}

int isEmpty(DLL l){
	if(l.front==NULL)
		return 1;
	return 0;
}

void append(DLL* l, int d){
	Node* nn=(Node*)malloc(sizeof(Node));
	nn->data=d;
	nn->prev=NULL;
	nn->next=NULL;
	if(!isEmpty(*l)){
		Node* p;
		p=l->front;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=nn;
		nn->prev=p;
		l->rear=nn;
	}else{
		l->rear=nn;
		l->front=nn;
	}
}

void insert_beg(DLL* l, int d){
	Node* current=l->front;
	Node *nn=(Node*)malloc(sizeof(Node));
	nn->data=d;
	nn->prev=NULL;
	nn->next=NULL;
	if(isEmpty(*l)==1){
		l->rear=nn;
		l->front=nn;
	}else{
		current->prev=nn;
		nn->next=current;
		l->front=nn;	
	}
}

void insert_pos(DLL* l,int d, int pos){
	if(pos==1){
		insert_beg(l,d);
		return;
	}
	Node *nn=(Node*)malloc(sizeof(Node));
	Node* temp=l->front;
	nn->data=d;
	int i;
	for(i=1;i<pos-1;i++){
		temp=temp->next;
	}
	nn->prev=temp;
	nn->next=temp->next;
	if(temp->next!=NULL){
		temp->next->prev=nn;
	}else{
		l->rear=nn;
	}
}

void remove_end(DLL* l){
	if(isEmpty(*l)==1){
		return;
	}
	Node* nn=l->rear;
	nn->prev->next=NULL;
	free(nn);
}

void remove_beg(DLL* l){
	if(isEmpty(*l)==1){
		return;
	}
	Node* temp=l->front;
	
	temp->next=NULL;
	free(temp);
}

void remove_pos(DLL* l, int pos){
	if(isEmpty(*l)==1){
		return;
	}
	if(pos==1){
		remove_beg(l);
		return;
	}
	int i;
	Node* temp=l->front;
	for(i=1;i<pos-1 && temp!=NULL;i++){
		temp=temp->next;
	}
	Node* nn=temp->next;
	if(temp->next!=NULL){
		temp->next=nn->next;
		nn->next->prev=temp;
		free(nn);
	}else{
		remove_end(l);
		return;
	}
	
}

int length(DLL l){
	int count=0;
	Node* current=l.front;
	while(current!=NULL){
		count++;
		current=current->next;
	}
	return count;
}

int search(DLL* l, int d){
	if(isEmpty(*l)==1){
		return 0;
	}else{
		Node* current=(*l).front;
		while(current!=NULL){
			if(current->data==d){
				return 1;
			}
			current=current->next;
		}
		return 0;
	}
}

void printLToR(DLL l){
	Node* p=l.front;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void printRToL(DLL l) {
    Node* p = l.rear;  
    while (p != NULL) {
        printf("%d ", p->data);  
        p = p->prev; 
    }
    printf("\n");
}

void sort(DLL* l){
	Node *i, *j;
	int temp;
	if(isEmpty(*l)==1){
		return;
	}
	for(i=l->front;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data > j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}

void isPalindrome(DLL* l){
	Node* i=l->front;
	Node* j=l->rear;
	while(i->next!=j && j->prev!=i){
		if(i->data!=j->data){
			printf("Not a Palindrome\n");	
			return;		
		}
		i=i->next;
		j=j->prev;
	}
	printf("Not a Palindrome\n");
}

void removeDup(DLL* l){
	
}

/*
// Function to remove duplicates from an unsorted linked list
void removeDuplicates(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    Node* prev = NULL;
    Node* temp = NULL;

    // Create a hash set (an array of boolean values) to track seen data values
    bool seen[1000] = {false};  // Assuming the data values are in the range 0-999

    while (current != NULL) {
        if (seen[current->data]) {
            // Duplicate found, remove it by updating the previous node's next pointer
            prev->next = current->next;
            free(current);
        } else {
            // Mark this data as seen
            seen[current->data] = true;
            prev = current;
        }
        current = prev->next;
    }
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(Node* head) {
    Node* current = head;
    
    // Traverse the list
    while (current != NULL && current->next != NULL) {
        // If current node's data is the same as the next node's data
        if (current->data == current->next->data) {
            // Skip the next node (remove it)
            Node* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        } else {
            // Move to the next node
            current = current->next;
        }
    }
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true; // Single node or empty list

    Node* slow = head;
    Node* fast = head;
    Node* stack = NULL;

    // Traverse the list and push the first half of elements onto the stack
    while (fast != NULL && fast->next != NULL) {
        push(&stack, slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Skip the middle element if the list has an odd number of nodes
    if (fast != NULL) {
        slow = slow->next;
    }

    // Compare elements from the second half with the stack
    while (slow != NULL) {
        int top = pop(&stack);
        if (top != slow->data) {
            return false; // Not a palindrome
        }
        slow = slow->next;
    }

    return true; // The list is a palindrome
}
*/
