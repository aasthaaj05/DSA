#include <stdio.h>

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void rDouble(double arr[], int *size){
    int n = *size;
    if (n == 0) {
        return;
    }
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                j--;
                n--;
            }
        }
    }
    *size = n; 
}

int main() {
    double arr[100];
    int i = 0;
    /*printf("Enter elements for array (press Ctrl+D to end input):\n"); */
    while (scanf("%lf", &arr[i]) != EOF) {
        i++;
    }
    /*printf("Original array:\n"); */
    printArray(arr, i);
    rDouble(arr, &i);
    /*printf("New array after removing duplicates:\n"); */
    printArray(arr, i);
    return 0;
}

