#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void displayMenu() {
    printf("\n\n***** Two Stacks Menu *****\n");
    printf("1. Push to Stack 1\n");
    printf("2. Push to Stack 2\n");
    printf("3. Pop from Stack 1\n");
    printf("4. Pop from Stack 2\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int size, choice, element;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    twoStacks* s = create(size);

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:  
                printf("Enter element to push to Stack 1: ");
                scanf("%d", &element);
                push1(s, element);
                break;

            case 2:  
                printf("Enter element to push to Stack 2: ");
                scanf("%d", &element);
                push2(s, element);
                break;

            case 3:  
                element = pop1(s);
                if (element != INT_MIN)
                    printf("Popped element from Stack 1: %d\n", element);
                break;

            case 4:  
                element = pop2(s);
                if (element != INT_MIN)
                    printf("Popped element from Stack 2: %d\n", element);
                break;

	    case 5:
                display(*s);
                break;
            case 6:  
                printf("Exiting the program...\n");
                free(s->a);
                free(s);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

