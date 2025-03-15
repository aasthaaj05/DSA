#include<stdio.h>
#include"heap.h"
#include<stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Heap* h=(Heap*)malloc(sizeof(Heap)); 
    init(h, 100); 
    
    readFileToHeap(h, argv[1]);

    printf("Original Heap:\n");
    printHeap(h);

    heap_sort(h);
    printf("Sorted Heap:\n");
    printHeap(h);

    free(h->A);  
    return EXIT_SUCCESS;
}
