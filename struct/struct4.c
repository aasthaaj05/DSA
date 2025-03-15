/*
Declare a structure fraction that has two fields— numerator and denominator. Create two variables and compare them using function. Return 0 if the two fractions are equal, –1 if the first fraction is less than the second and 1 otherwise. You may convert a fraction into a floating point number for your convenience.
*/

#include<stdio.h>

typedef struct fraction{
	int num;
	int den;
}Fraction;

int main(){
	Fraction fraction1, fraction2;
	int result;
	printf("Numerator of First fraction: ");
	scanf("%d", &fraction1.num);
	printf("Denominator of First fraction: ");
	scanf("%d", &fraction1.den);
	printf("Numerator of Second fraction: ");
	scanf("%d", &fraction2.num);
	printf("Denominator of Second fraction: ");
	scanf("%d", &fraction2.den);
	float ans1=(float)fraction1.num/fraction1.den;
	float ans2=(float)fraction2.num/fraction2.den;
	if(ans1==ans2){
		result=0;
	}else if(ans1>ans2){
		result=1;
	}else{
		result=-1; 
	}
	printf("%d", result);
}
