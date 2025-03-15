#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int val;
    int flag;  
} Item;

typedef struct {
    Item table[TABLE_SIZE];
} HashTable;

void init(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].val = -1;
        ht->table[i].flag = 0;
    }
}

int division(int key) {
    return key % TABLE_SIZE;
}

int double_hash(int key) {
    int prime = 7; 
    return prime - (key % prime);
}

void insert(HashTable* ht, int key) {
    int index = division(key);
    
    if (ht->table[index].flag!=0) {
        printf("Collision detected at index %d for key %d. Using double hashing.\n", index, key);
        int step = double_hash(key); 
        int i = 1;
        while (ht->table[index].flag && i < TABLE_SIZE) {
            index = (index + step) % TABLE_SIZE;  
            i++;
        }
    }
    
    if (ht->table[index].flag==0) {
        ht->table[index].val = key;
        ht->table[index].flag = 1;
    } else {
        printf("Table overflow\n");
    }
}

void print(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i].flag) {
            printf("%d: %d\n", i, ht->table[i].val);
        } 
    }
}

int main() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    init(ht);
    int keys[] = {20, 50, 73, 19, 6, 77, 10, 55, 44, 92, 36, 25};
    int size = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < size; i++) {
        insert(ht, keys[i]);
    }
    print(ht);
    free(ht);
}

