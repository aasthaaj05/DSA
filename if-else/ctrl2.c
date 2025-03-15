/*
Write a program that asks the user to enter an integer and determines whether it is divisible by 5 and 6, whether it is divisible by 5 or 6, and whether it is divisible by 5 or 6 but not both.
For example, if your input is 10, the output should be:
Is 10 divisible by 5 and 6? false //Is 10 divisible by 5 or 6? true
Is 10 divisible by 5 or 6, but not both? True 
*/

#include<stdio.h>

int main(){
	int a;
	printf("enter a number\n"); 
	scanf("%d", &a);
	if(a%6==0 && a%5==0){
		printf("It is divisible by both 5 and 6\n");
	}else if((a%6!=0 && a%5==0) || (a%6==0 && a%5!=0)){
		printf("It is divisible by either 5 or 6 but not both\n");
	}else if((a%6!=0 && a%5!=0) || (a%6!=0 && a%5!=0)){
		printf("It is divisible by neither 5 nor 6\n");
	}
	return 0;
}
