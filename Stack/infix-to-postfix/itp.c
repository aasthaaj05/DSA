#include<stdio.h>
#include"itp.h"
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include <ctype.h>

void init(stack* s) {
    s->top = NULL;
}

void push(stack* s, char c) {
    INode* nn = (INode*)malloc(sizeof(INode));
    nn->data = c;
    nn->next = s->top;
    s->top = nn;
}

char pop(stack* s) {
    if (s->top == NULL) return '\0';
    INode* temp = s->top;
    char res = temp->data;
    s->top = s->top->next;
    free(temp);
    return res;
}

int isOperator(char c) {
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-');
}

char peek(stack* s) {
    if (s->top == NULL) return '\0';
    return s->top->data;
}

int priority(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

char* inToPost(char* infix) {
    stack* s = (stack*)malloc(sizeof(stack)); 
    init(s);

    int len = strlen(infix);
    char* res = (char*)malloc(sizeof(char) * (2 * len + 1));  
    int i = 0, j = 0;

    while (i < len) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                res[j++] = infix[i++];
            }
            res[j++] = ' ';  
            i--;  
        } 
        else if (infix[i] == '(') {
            push(s, '(');
        } 
        else if (infix[i] == ')') {
            while (peek(s) != '(') {
                res[j++] = pop(s);
                res[j++] = ' '; 
            }
            pop(s);  
        } 
        else if (isOperator(infix[i])) {
            while (s->top != NULL && priority(peek(s)) >= priority(infix[i])) {
                res[j++] = pop(s);
                res[j++] = ' ';  
            }
            push(s, infix[i]);
        }
        i++;
    }

    while (s->top != NULL) {
        res[j++] = pop(s);
        res[j++] = ' ';  
    }

    res[j - 1] = '\0';  
    free(s);  
    return res;
}

void init2(stack2* s) {
    s->top = NULL;
}

void push2(stack2* s, int d) {
    IINode* nn = (IINode*)malloc(sizeof(IINode));
    nn->data = d;
    nn->next = s->top;
    s->top = nn;
}

int pop2(stack2* s) {
    if (s->top == NULL) return INT_MIN;
    IINode* temp = s->top;
    int d = temp->data;
    s->top = s->top->next;
    free(temp);
    return d;
}

int evalPost(char* post) {
    stack2 s;
    init2(&s);
    int i = 0, num = 0;

    while (post[i] != '\0') {
        if (isdigit(post[i])) {
            num = 0;
            while (isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            push2(&s, num);
        } else if (isOperator(post[i])) {
            int op2 = pop2(&s);
            int op1 = pop2(&s);

            switch (post[i]) {
                case '^': 
                    push2(&s, pow(op1, op2));
                    break;
                case '/': 
                    push2(&s, op1 / op2);
                    break;
                case '*': 
                    push2(&s, op1 * op2);
                    break;
                case '+': 
                    push2(&s, op1 + op2);
                    break;
                case '-': 
                    push2(&s, op1 - op2);
                    break;
            }
        }
        i++;
    }

    return pop2(&s);  
}

