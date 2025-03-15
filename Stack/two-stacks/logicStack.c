#include"stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

twoStacks* create(int n){
	twoStacks *s=(twoStacks*)malloc(sizeof(twoStacks));
	s->a=(int *)malloc(sizeof(int)* n);
	s->size=n;
	s->top1=-1;
	s->top2=n;
	return s;	
}

void push1(twoStacks* s, int x){
	if(s->top1<s->top2-1){
		s->a[++s->top1]=x;
	}else
		return;
}

void push2(twoStacks* s, int x){
	if(s->top1<s->top2-1){
		s->a[--s->top2]=x;
	}else
		return;
}

int pop1(twoStacks* s){
	if(s->top1 >=0){
		int x=s->a[s->top1--];		
		return x;		
	}else{
		return INT_MIN;
	}
}

int pop2(twoStacks* s){
	if(s->top2 < s->size){
		int x=s->a[s->top2++];		
		return x;		
	}else{
		return INT_MIN;
	}
}

void display(twoStacks s) {
    int i;
    printf("\nStack 1: ");
    if (s.top1 >= 0) {
        for (i = 0; i <= s.top1; i++) {
            printf("%d ", s.a[i]);
        }
    } else {
        printf("Empty");
    }
    printf("\nStack 2: ");
    if (s.top2 < s.size) {
        for (i = s.top2; i < s.size; i++) {
            printf("%d ", s.a[i]);
        }
    } else {
        printf("Empty");
    }
    printf("\n");
}

