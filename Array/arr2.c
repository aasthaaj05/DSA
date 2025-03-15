#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int result[100];
    int i, j = 0;
    srand(time(0));
    for (i = 0; i < 100; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    printf("Original array:\n");
    printArray(arr, 100);
    for (i = 0; i < 100; i++) {
        if (arr[i] % 8 == 0 || arr[i] % 15 == 0) {
            result[j++] = arr[i];
        }
    }
    printf("\nNumbers divisible by 8 or 15:\n");
    printArray(result, j);
    return 0;
}

