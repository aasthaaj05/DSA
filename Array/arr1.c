/*
Display array elements in reverse. ie from last to first.
*/

#include<stdio.h>
void reverse(int arr[], int n){
	int i=0,j=n-1;
	while(i<j){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
}
void printArr(int arr[], int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr [5]={1,2,3,4,5}; 
	printf("Orignal array: ");
	printArr(arr, 5); 
	reverse(arr,5);
	printf ("Reversed array: "); 
	printArr(arr, 5);
}
