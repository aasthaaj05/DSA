/*
Define a structure date containing three integers— day, month, and year. Write a program using functions to read data, to validate the date entered by the user and then print the date on the screen. For example, if you enter 29/2/2010 then that is an invalid date as 2010 is not a leap year. Similarly 31/6/2007 is invalid as June does not have 31 days.
*/
#include<stdio.h>

typedef struct date{
	int day;
	int month;
	int year;
}Date;

int leapYear(Date date){
	int result;
	if(date.year%4==0 && date.year%100==0){
		result=1;
	}else if(date.year%4!=0 && date.year%100==0){
		result=-1;
	}else if(date.year%4!=0){
		result=-1;
	}else if(date.year%4==0 && date.year%100!=0){
		result=1;
	}
	return result;
}

int main(){
	Date date;
	int valid=0;
	printf("Day of month ");
	scanf("%d",&date.day);
	printf("Month of year ");
	scanf("%d",&date.month);
	printf("Year ");
	scanf("%d",&date.year);
	int ly=leapYear(date);
	switch(date.month){
		case 1:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		case 2:
			if(ly==1){
				if(date.day>=1 && date.day<=29){
					valid=1;	
				}
			}else{
				if(date.day>=1 && date.day<=28){
					valid=1;	
				}
			}
			break;
		case 3:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		case 4:
			if(date.day>=1 && date.day<=30){
				valid=1;	
			}
			break;
		case 5:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		case 6:
			if(date.day>=1 && date.day<=30){
				valid=1;	
			}
			break;
		case 7:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		case 8:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		case 9:
			if(date.day>=1 && date.day<=30){
					valid=1;	
			}
			break;
		case 10:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		case 11:
			if(date.day>=1 && date.day<=30){
				valid=1;	
			}
			break;
		case 12:
			if(date.day>=1 && date.day<=31){
				valid=1;	
			}
			break;
		default:
			printf("Invalid input\n");
	}
	if(valid==1){
		printf("%d %d %d", date.day, date.month, date.year);
	}else{
		printf("Invalid");
	}
	
}
