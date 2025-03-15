//Circular Que

#include <stdio.h>

int f = -1;
int r = -1;

// isemp
int isemp() {
    if (f == -1 && r == -1) {
        return 1;
    }
    return 0;
}

// isfull
int isfull(int sizeArr) {
    if ((r == sizeArr - 1 && f==0) || r==f-1) {
        return 1;
    }
    return 0;
}

// add
void add(int arr[], int sizeArr, int data) {
    if (isfull(sizeArr)) {
        printf("Overflow\n");
        return;
    }
    if (isemp()) {
        f = 0;
        r = 0;
    } else if(f!=0 && r==sizeArr-1){
    	r=0;
     }else {
        r++;
    }
    arr[r] = data;
}

// del
void del(int sizeArr) {
    if (isemp()) {
        printf("Underflow\n");
        return;
    }
    if (f == r) { 
        f = -1;
        r = -1;
    } else if(f==sizeArr-1){
    	f=0;
     } else {
        f++;
    }
}

// printArray
void printArray(int arr[], int sizeArr) {
    if (isemp()) {
        printf("Array is empty\n");
        return;
    }
    if (r >= f) {
        for (int i = f; i <= r; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for (int i = f; i < sizeArr; i++) {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i <= r; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[5];

    add(arr, 5, 1);
    add(arr, 5, 2);
    add(arr, 5, 3);
    printArray(arr, 5);

    del(5);
    printArray(arr, 5); 

    add(arr, 5, 4);
    add(arr, 5, 5);
    add(arr, 5, 6); 
    add(arr, 5, 7); 
    printArray(arr, 5); 
    
    del(5);
    del(5);
    del(5);
    del(5);
    del(5);
    del(5);
    
    printArray(arr, 5); 
    return 0;
}

