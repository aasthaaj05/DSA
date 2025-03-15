#include<stdio.h>
#include<stdlib.h>

//creating node
struct node{
	int data;
	struct node* link;
};

//empty
void isemp(struct node* head){
	if(head==NULL){
		printf("linked list is empty");	
	}
}

//counting no. of nodes
void no_of_nodes(struct node* head){
	int count=0;
	isemp(head);
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL){
		count++;
		ptr=ptr->link;
	}
	printf("Number of nodes in LL are %d\n", count);
}

//printing data
void print(struct node* head){
	isemp(head);
	struct node *ptr=NULL;
	ptr=head;
	printf("data:\n");
	while(ptr!=NULL){
		printf("%d\n", ptr->data);
		ptr=ptr->link;
	}
}

//insertion at beginning
struct node* add_beg(struct node* head,int data){
	isemp(head);
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->link=NULL;
	ptr->link=head;
	head=ptr;
	printf("data added at beg\n");
	return head;
}

//insertion at end
void add_end(struct node* head,int data){
	struct node* ptr, *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	temp->data=data;
	temp->link=NULL;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	ptr->link=temp;
	printf("data added at end\n");
}

//insertion at pos
void add_pos(struct node* head, int data, int pos){
	struct node* ptr, *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	temp->data=data;
	temp->link;
	pos--;
	while(pos!=1){
		ptr=ptr->link;
		pos--;
	}
	temp->link=ptr->link;
	ptr->link=temp;
	printf("data added at pos\n");
}

//deletion at beginning
struct node* del_beg(struct node* head){
	head=head->link;
	printf("data deleted at beg\n");
	return head;
}


//deletion at end
void del_end(struct node* head){
	isemp(head);
		struct node* temp1, *temp2;
		temp1=head;
		temp2=head;
		while(temp2->link!=NULL){
			temp1=temp2;
			temp2=temp2->link;
		}
		temp1->link=NULL;
		free(temp2);
		temp2=NULL;
	
	printf("data deleted at end\n");
}

//deletion in between
void del_pos(struct node* head, int pos){
	isemp(head);
	    if (pos == 1) {
		del_beg(head);
	    }
	    struct node* ptr1 = head;
	    struct node* ptr2 = NULL;
	    for (int i = 1; i < pos; i++) {
		ptr2 = ptr1;
		ptr1 = ptr1->link;
	    }
	    ptr2->link = ptr1->link;
	    free(ptr1);
	    printf("Node deleted at position %d\n", pos);
    
}

//search in ll
void search(struct node* head, int data){
	struct node* ptr=head;
	while(ptr!=NULL){
		if(ptr->data==data){
			printf("found\n");
		}
		ptr=ptr->link;
	}
}

//reversal of ll
struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* next = NULL;
    
    while (head != NULL) {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    
    printf("Linked list reversed\n");
    head = prev;
    return head;
}



int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->link = second;

    second->data = 2;
    second->link = third;

    third->data = 3;
    third->link = NULL;

    printf("Initial state of the linked list:\n");
    no_of_nodes(head);
    print(head);
    
    add_end(head,4);
    print(head);
    
    head=add_beg(head,0);
    print(head);
    
    add_pos(head,101,3);
    print(head);
    
    head=del_beg(head);
    print(head);
    
    del_end(head);
    print(head);
    
    del_pos(head,2);
    print(head);
    
    printf("Searching in data:");
    search(head,2);
    
    head=reverse(head);
    print(head);
    
    
  

    free(third);
    free(second);
    free(head);

    head = NULL;


    return 0;
}
