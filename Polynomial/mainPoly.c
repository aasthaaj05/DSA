#include"poly.h"
#include<stdio.h>
#include<stdlib.h>

/*
typedef struct term{
	int c;
	int e;
};

typedef struct poly{
	int n;
	term* t;
};

void init(poly* p, int size);
void append(poly* p, int c, int e);
void display(poly* p, int size);
int add_poly(poly* p, poly* q, poly* result);
void sub_poly(poly* p, poly* q, poly* result);
*/

int main() {
    int c, e, size, choice;
    poly p, q, result;
    while (1) {
        printf("1. Init\n");
        printf("2. Append\n");
        printf("3. Display\n");
        printf("4. Add poly\n");
        printf("5. Sub Poly\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the size of the Polynomial: ");
                scanf("%d", &size);
                init(&p, size);
                init(&q, size);   // Initialize both polynomials
                init(&result, size); // Initialize result polynomial
                break;
            case 2:
                printf("Enter coeff of term: ");
                scanf("%d", &c);
                printf("Enter exponent of term: ");
                scanf("%d", &e);
                append(&p, c, e);
                break;
            case 3:
                printf("Polynomial:\n");
                display(&p);
                break;
            case 4:
                printf("Enter terms for the second polynomial:\n");
                for (int i = 0; i < p.n; i++) {
                    printf("Enter coeff of term: ");
                    scanf("%d", &c);
                    printf("Enter exponent of term: ");
                    scanf("%d", &e);
                    append(&q, c, e);
                }
                add_poly(&p, &q, &result);
                printf("Resultant Polynomial after addition:\n");
                display(&result);
                break;
            case 5:
                printf("Enter terms for the second polynomial:\n");
                for (int i = 0; i < p.n; i++) {
                    printf("Enter coeff of term: ");
                    scanf("%d", &c);
                    printf("Enter exponent of term: ");
                    scanf("%d", &e);
                    append(&q, c, e);
                }
                sub_poly(&p, &q, &result);
                printf("Resultant Polynomial after subtraction:\n");
                display(&result);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
