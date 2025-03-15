#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i++) {
        int ind = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[ind]) ind = j;
        }
        swap(&arr[i], &arr[ind]);
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter size of array\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter integers to be sorted in the array\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    selectionSort(arr, size);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Array: ");
    display(arr, size);
    printf("Time taken for selection sort: %.6f seconds\n", time_taken);

    return 0;
}

