/*
Taste Salary cal RA -363 DaY Bf an employee and calculate its Gross salary according to following
Basic Salary <= 10000: HRA = 20%, DA = 80%
Basic Salary <= 20000: HRA = 25%, DA = 90%
Basic Salary > 20000: HRA = 30%, DA = 95%
gross salary= basic salary + HRA + DA
*/
#include<stdio.h>

int main (){
	int a; 
	float gs;
	printf("enter the salary\n");
	scanf ("%d", &a);
	if(a<=10000){
		gs=a+a*0.2+a*0.8;
	}else if(a<=20000){
		gs=a+a*0.25+a*0.9;
	}else if(a>20000){
		gs=a+a*0.3+a*0.95;
	}
	printf ("Gross salary = %f\n", gs);
	return 0;
}
