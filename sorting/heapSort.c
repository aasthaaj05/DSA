#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct heap {
    int* A;
    int size, rear;
} Heap;

void init(Heap* h, int size) {
    h->rear = -1;
    h->size = size;
    h->A = (int*)malloc(sizeof(int) * size);
}

void swap(Heap* h, int a, int b) {
    if (a >= h->size || b >= h->size) return;
    int temp = h->A[a];
    h->A[a] = h->A[b];
    h->A[b] = temp;
}

int parent(int ind) {
    return (ind - 1) / 2;
}

void printHeap(Heap* h) {
    for (int i = 0; i <= h->rear; i++)
        printf("%d ", h->A[i]);
    printf("\n");
}

void insert(Heap* h, int value) {
    if (h->rear == h->size - 1) return;  
    h->A[++h->rear] = value;
    int i = h->rear;
    while (i > 0 && h->A[parent(i)] < h->A[i]) { 
        swap(h, i, parent(i));
        i = parent(i);
    }
}

void heapifyDown(Heap* h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left <= h->rear && h->A[left] > h->A[largest]) {
        largest = left;
    }
    if (right <= h->rear && h->A[right] > h->A[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(h, index, largest);
        heapifyDown(h, largest);  
    }
}

void heap_sort(Heap* h) {
    int originalRear = h->rear; 
    for (int i = h->rear / 2; i >= 0; i--) {
        heapifyDown(h, i);
    }
    for (int i = h->rear; i > 0; i--) {
        swap(h, 0, i);       
        h->rear--;           
        heapifyDown(h, 0);   
    }
    h->rear = originalRear;  
}

int main() {
    int size;
    printf("Enter the size of the heap: ");
    scanf("%d", &size);
    Heap h;
    init(&h, size);
    printf("Enter %d elements to insert into the heap:\n", size);
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        insert(&h, value);
    }
    clock_t start = clock();
    heap_sort(&h);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Heap after sorting: ");
    printHeap(&h);
    printf("Time taken for heap sort: %.6f seconds\n", time_taken);

    free(h.A);  
    return 0;
}

