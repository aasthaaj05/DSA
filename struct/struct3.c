/*
Declare a structure time that has three fields—hr, min, sec. Create two variables start_time and end_time. Input their values from the user. Then while start_time does not reach the end_time, display GOOD DAY on the screen
*/

#include<stdio.h>

typedef struct time{
	int hr;
	int min;
	int sec;
}Time;

int main(){
	Time start_time, end_time;
	printf("start time hr: ");
	scanf("%d", &start_time.hr);
	printf("start time min: ");
	scanf("%d", &start_time.min);
	printf("start time sec: ");
	scanf("%d", &start_time.sec);
	printf("end time hr: ");
	scanf("%d", &end_time.hr);
	printf("end time min: ");
	scanf("%d", &end_time.min);
	printf("end time sec: ");
	scanf("%d", &end_time.sec);
	if(end_time.hr<24 && start_time.hr<24 && end_time.min<60 && start_time.min<60 && end_time.sec<60 && start_time.sec<60){
		if(end_time.hr>start_time.hr){
			printf("GOOD DAY");
		}else if(end_time.hr==start_time.hr){
			if(end_time.min>start_time.min){
				printf("GOOD DAY");
			}else if(end_time.min==start_time.min){
				if(end_time.sec>start_time.sec){
					printf("GOOD DAY");
				}	
			}
		}
	}else{
		printf("invalid inputs");
	}
	return 0;
}
