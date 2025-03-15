#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include"stack2.h"  

int main() {
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    int len = strlen(str);
    
    stack s;
    init(&s, len);
    reverse(&s, str);
    printf("Reversed string: %s\n", str);
    free(s.A);

    char expression[100];
    printf("\nEnter a parenthesis expression to validate: ");
    scanf("%s", expression);

    if (isValid(expression)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is invalid.\n");
    }

    int decimal;
    printf("\nEnter a decimal number to convert to binary: ");
    scanf("%d", &decimal);
    printf("Binary of %d is: ", decimal);
    decToBin(decimal);

    return 0;
}

