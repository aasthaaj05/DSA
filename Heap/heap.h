typedef struct heap{
	int* A;
	int size, rear;
}Heap;

void init(Heap* h, int size);
void swap(Heap* h, int a, int b);
int parent(int ind);
void printHeap(Heap* h);
void insert(Heap* h, int value);
void heap_sort(Heap* h);
void heapify(Heap* h);
void readFileToHeap(Heap* h, const char* filename);
