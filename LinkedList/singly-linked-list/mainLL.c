#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "list.h"

/*
void init(list *head);
void traverse(list head);
void append(list* l, int d);
int length(list *l);
void insert_at_beg(list *l, int data);
void remove_at_pos(list *l, int pos);
*/

int main(){
	int choice, d, pos, len;
	list l;
	while(1){
		printf("1. Init\n");
		printf("2. Append\n");
		printf("3. Length\n");
		printf("4. Traverse\n");
		printf("5. Insert at begin\n");
		printf("6. Remove at Position\n");
		printf("7. exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				init(&l);
				break;
			case 2:
				printf("Enter value to append: ");
				scanf("%d", &d);
				append(&l, d);
				break;
			case 3:
				len=length(&l);
				printf("length is %d\n", len);
				break;
			case 4:
				traverse(l);
				break;
			case 5:
				printf("Enter value to insert at beg: ");
				scanf("%d", &d);
				insert_at_beg(&l, d);
				break;
			case 6:
				printf("Enter value of position \n");
				scanf("%d", &pos);
				remove_at_pos(&l, pos);
				break;
			case 7:
				exit(0);
			default:
                       	printf("Invalid choice. Please try again.\n");
		
		}	
	}
	return 0;
}
