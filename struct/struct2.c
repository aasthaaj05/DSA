/*
Q.3 Write a program to define a structure for a hotel that has members— name, address, grade, number of rooms, and room charges. Write a function to print the names of hotels in a particular grade. Also write a function to print names of hotels that have room charges less than the specified value.
*/

#include<stdio.h>

typedef struct member{
	char name[56];
	char address[128];
	char grade;
	int number;
	float charges;
}Member;

void displayPriceAcc(Member member[], int n, float price){
	int i;
	for(i=0;i<n;i++){
		if(member[i].charges<=price){
			printf("%s \n", member[i].name);
		}
	}
}

void displayGradeAcc(Member member[], int n, char grd){
	int i;
	for(i=0;i<n;i++){
		if(member[i].grade==grd){
			printf("%s \n", member[i].name);
		}
	}
}

int main(){
	int i, n;
	float price;
	char grd;
	printf("No. of Hotels\n");
	scanf("%d", &n);
	Member member[n];
	for(i=0;i<n;i++){
		printf("Name of hotel\n");
		scanf("%s", member[i].name);
		printf("Address of hotel\n");
		scanf("%s", member[i].address);
		printf("Grade of hotel (A/B/C)\n");
		getchar();
		scanf("%c", &member[i].grade);
		printf("Number of rooms in hotel\n");
		scanf("%d", &member[i].number);
		printf("charges of room\n");
		scanf("%f", &member[i].charges);
	}
	printf("Budget Price: ");
	scanf("%f", &price);
	displayPriceAcc(member, n, price);
	printf("Grade Desired: ");
	getchar();	
	scanf("%c", &grd);
	displayGradeAcc(member, n, grd);
	return 0;
}
