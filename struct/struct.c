/*
Using the above structure, write a program to display the details of the student whose
name is entered by the user. Display the name of the students who have secured less than
40% of the aggregate. In addition, print each student’s average marks
*/

#include<stdio.h>
typedef struct {
		char fname[20];
		char mname[20];
		char lname[20];
}Name;

typedef struct {
		int day;
		int month;
		int year;
}Dob;

typedef struct {
		float english;
		float mathematic;
		float compsci;
}Marks;

typedef struct student{
	long rollno;
	Name name;
	char gender[20];
	Dob dob;
	Marks marks;
}Student;

float avg(Marks marks){
	float result=(marks.english+marks.mathematic+marks.compsci)/3.0;
	return result;
}

void displayAll(Student student[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%ld %s %s %s %s %d %d %d %f %f %f\n", 
			student[i].rollno,
			student[i].name.fname,
			student[i].name.mname,
			student[i].name.lname,
			student[i].gender,
			student[i].dob.day,
			student[i].dob.month,
			student[i].dob.year,
			student[i].marks.english,
			student[i].marks.mathematic,
			student[i].marks.compsci);
	}
}

void agg40Display(Student student[], int n){
	int i;
	for(i=0;i<n;i++){
		float average=avg(student[i].marks);
		if(average<40){
			printf("%s %s %s %f\n", student[i].name.fname, student[i].name.mname, student[i].name.lname, average);
		}
	}
}

int main(){
	printf("Enter number of students\n");
	int n;
	Student student[n];
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i++){
		printf("Enter rollno\n");
		scanf("%ld", &student[i].rollno);
		printf("Enter first name\n");
		scanf("%s", student[i].name.fname);	
		printf("Enter middle name\n");
		scanf("%s", student[i].name.mname);
		printf("Enter last name\n");
		scanf("%s", student[i].name.lname);
		printf("Enter gender\n");
		scanf("%s", student[i].gender);
		printf("Enter DOB day\n");
		scanf("%d", &student[i].dob.day);
		printf("Enter DOB month\n");
		scanf("%d", &student[i].dob.month);
		printf("Enter DOB year\n");
		scanf("%d", &student[i].dob.year);
		printf("Enter marks english\n");
		scanf("%f", &student[i].marks.english);
		printf("Enter marks mathematic\n");
		scanf("%f", &student[i].marks.mathematic);			
		printf("Enter marks compsci\n");
		scanf("%f", &student[i].marks.compsci);	
	}
	displayAll(student, n);
	agg40Display(student, n);
	return 0;
}
