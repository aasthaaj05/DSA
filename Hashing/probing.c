#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int val;
    int isOccupied; 
} Item;

void init(Item* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].val = -1;
        table[i].isOccupied = 0;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertLinear(Item* table, int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (table[index].isOccupied) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) { 
            printf("Hash table is full. Cannot insert key %d.\n", key);
            return;
        }
    }
    table[index].val = key;
    table[index].isOccupied = 1;
}

void printLP(Item* table) {
    printf("Linear Probing Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].isOccupied) {
            printf("%d: %d\n", i, table[i].val);
        } else {
            printf("%d: EMPTY\n", i);
        }
    }
}

void insertQuadratic(Item* table, int key) {
    int index = hashFunction(key);
    int i = 0;
    int originalIndex = index;
    while (table[(index + i * i) % TABLE_SIZE].isOccupied) {
        i++;
        if (i == TABLE_SIZE){ 
            printf("Hash table is full. Cannot insert key %d.\n", key);
            return;
        }
    }
    index = (index + i * i) % TABLE_SIZE;
    table[index].val = key;
    table[index].isOccupied = 1;
}

void printQP(Item* table) {
    printf("Quadratic Probing Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].isOccupied) {
            printf("%d: %d\n", i, table[i].val);
        } else {
            printf("%d: EMPTY\n", i);
        }
    }
}

int main() {
    Item linearTable[TABLE_SIZE];
    Item quadraticTable[TABLE_SIZE];

    init(linearTable);
    init(quadraticTable);

    int keys[] = {20, 30, 40, 50, 22, 42, 53, 66, 77, 18};
    int size = sizeof(keys) / sizeof(keys[0]);

    printf("Linear Probing:\n");
    for (int i = 0; i < size; i++) {
        insertLinear(linearTable, keys[i]);
    }
    printLP(linearTable);

    printf("\nProbing:\n");
    for (int i = 0; i < size; i++) {
        insertQuadratic(quadraticTable, keys[i]);
    }
    printQP(quadraticTable);

    return 0;
}

