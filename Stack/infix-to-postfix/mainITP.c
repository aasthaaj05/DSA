#include<stdio.h>
#include"itp.h"
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%[^\n]", infix);

    char* postfix = inToPost(infix);
    printf("Postfix expression: %s\n", postfix);

    int result = evalPost(postfix);
    printf("Result of evaluation: %d\n", result);

    free(postfix);
    return 0;
}

