#include<stdio.h>

int linear(int arr[], int size, int key){
	for(int i=0;i<size;i++){
		if(arr[i]==key) return i;
	}
	return -1;
}

int binary(int arr[],int size,int key){
	int l=0;
	int r=size-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(arr[mid]==key) return mid;
		else if(arr[mid]>key){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return -1;
}

int main(){
	int size, key;
	printf("Enter size of array\n");
	scanf("%d", &size);
	int arr[size], arr2[size];
	printf("Enter array of integers for linear search\n");
	for(int i=0;i<size;i++){
		scanf("%d", &arr2[i]);
	}
	printf("Enter sorted array of integers for binary search\n");
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter key to be found\n");
	scanf("%d", &key);
	int res1=linear(arr2,size,key);
	int res2=binary(arr,size, key);
	if(res1==-1){
		printf("key not found in array of linear search\n");
		printf("key found by binary search at index: %d\n", res2);
	}else if(res2==-1){
		printf("key not found in array of binary search\n");
		printf("key found by linear search at index: %d\n", res1);
	}else if(res1==-1 && res2==-1){
		printf("key not found in both");
	}else{
		printf("key found by linear search at index: %d\n", res1);
		printf("key found by binary search at index: %d\n", res2);
	}
	
}
