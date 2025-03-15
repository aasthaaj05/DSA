#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

//print
void print(struct node* head){
	struct node *ptr=NULL;
	ptr=head;
	printf("data:\n");
	while(ptr!=NULL){
		printf("%d\n", ptr->data);
		ptr=ptr->next;
	}
}

//insert at beg
struct node* add_beg(struct node* head, int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->next=head;
	new->prev=NULL;
	head=new;
	printf("add at beg\n");
	return head;
}

//insert at end
void add_end(struct node* head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	struct node* ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	new->data=data;
	ptr->next=new;
	new->prev=ptr;
	new->next=NULL;
	printf("add at and\n");
}

//insert at pos
void add_pos(struct node* head, int data, int pos){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	int i;
	struct node* ptr=head;
	struct node* ptr1=NULL;
	for(i=1;i<pos-1;pos--){
		ptr=ptr->next;
	}
	ptr1=ptr->next;
	new->next=ptr1;
	ptr->next=new;
		
	printf("add at pos\n");
}

//del at beg
struct node* del_beg(struct node* head){
	struct node* ptr=head->next;
	head=ptr;
	printf("del at beg\n");
	return head;
}

//del at end
void del_end(struct node* head){
	struct node* ptr=head;
	struct node* ptr1=head;
	while(ptr->next!=NULL){
		ptr1=ptr;
		ptr=ptr->next;
	}
	ptr1->next=NULL;
	free(ptr);
	
	printf("del at end\n");
}

//del at pos
void del_pos(struct node* head, int pos){
	int i;
	struct node* ptr=head;
	struct node* ptr1=NULL;
	for(i=1;i<pos-1;pos--){
		ptr=ptr->next;
	}
	printf("del at pos\n");
}



int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    print(head);
    
    head=add_beg(head,0);
    print(head);
    
    add_end(head,4);
    print(head);
    
    add_pos(head,101,3);
    print(head);
    
    head=del_beg(head);
    print(head);
    
    del_end(head);
    print(head);
    
    del_pos(head,2);
    print(head);
    
    free(third);
    free(second);
    free(head);

    return 0;
}


