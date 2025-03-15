#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size of array\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter integers to be sorted in the array\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    display(arr, size);
    printf("Time taken for bubble sort: %.6f seconds\n", time_taken);

    return 0;
}

