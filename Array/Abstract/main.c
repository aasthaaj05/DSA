#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int main(){
	array a, b, *c;
	int choice,size,val,ind, ind1, maxi;
	while(1){
		printf("1. Init\n");
		printf("2. Append\n");
		printf("3. Insert at index\n");
		printf("4. Remove at index\n");
		printf("5. Display\n");
		printf("6. Max\n");
		printf("7. Reverse\n");
		printf("8. Exit\n");
		printf("9. Merge two arrays\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter the size of the array: ");
				scanf("%d", &size);
				init(&a, size);
				break;
			case 2:
				printf("Enter value to append: ");
				scanf("%d", &val);
				append(&a, val);
				break;
			case 3:
				printf("Enter index to insert at: ");
				scanf("%d", &ind1);
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insert_at_index(&a, ind1, val);
				break;
			case 4:
				printf("Enter value of position to remove: ");
				scanf("%d", &ind);
				remove_at_index(&a, ind);
				break;
			case 5:
				display(&a);
				break;
			case 6:
				maxi=max(&a);
				printf("%d is the max val\n", maxi);
				break;
			case 7:
				reverse(&a);
				display(&a);
				break;
			case 8:
				exit(0);
			case 9:
				printf("Enter size for the second array: ");
				scanf("%d", &size);
				init(&b, size);
				display(&b);
				c=merge(&a, &b);
				display(c);
				break;
			default:
                       	printf("Invalid choice. Please try again.\n");
		
		}	
	}
	return 0;
}



