#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include"stack2.h"

void init(stack *s, int len){
	s->size=len;
	s->top=-1;
	s->A=(char*)malloc(sizeof(char)*len);
}

void push(stack *s, char data){
	if(isFull(*s)!=INT_MAX){
		s->A[++s->top]=data;
	}
}

int isFull(stack s){
	if(s.top==s.size-1)
		return INT_MAX;
	return 0;
}

int isEmpty(stack s){
	if(s.top==-1)
		return INT_MIN;
	return 0;
}

char pop(stack *s){
	if(isEmpty(*s) != INT_MIN){
        	return s->A[s->top--]; 
    	} 
    	return '\0';
}

void reverse(stack *s, char *str){
	int i;
    	int len = s->size;
	for(i = 0; i < len; i++) {
        	push(s, str[i]);
    	}
	for(i = 0; i < len; i++) {
        	str[i] = pop(s);
    	}
}

void decToBin(int dec) {
    stack* s = (stack*)malloc(sizeof(stack));
    init(s, 32);  
    while(dec != 0) {
        push(s, (dec % 2) + '0');  
        dec = dec / 2;
    }
    while(!isEmpty(*s)) {  
        printf("%c", pop(s));
    }  
    printf("\n");
    free(s->A);
    free(s);
}

int isOpen(char ch){
	if(ch=='('||ch=='{'||ch=='[')
		return 1;
	return 0;
}

int isClose(char ch){
	if(ch==')'||ch=='}'||ch==']')
		return 1;
	return 0;
}

int match(char ch1, char ch2){
	if((ch1=='(' && ch2==')')||(ch1=='{' && ch2=='}')||(ch1=='[' && ch2==']'))
		return 1;
	return 0;
}

int isValid(char* str){
	int i, len=strlen(str);
	stack* s=(stack*)malloc(sizeof(stack));
	init(s,len+1);
	for(i=0;i<len;i++){
		char ch=str[i];
		if(isOpen(ch)){
			push(s, ch);
		}else if(isClose(ch)){
			if(isEmpty(*s))
				return 0;
			char top = pop(s);
			if (!match(top, ch)) 
				return 0;
		}
	}
	return isEmpty(*s);
}
