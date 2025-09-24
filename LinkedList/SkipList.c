#include <stdio.h>
#include <limits.h> 
#include <stdlib.h>
#include <time.h>

#define SKIPLIST_MAX_LEVEL 16
#define P 0.5   

typedef struct Node {
    int val;
    struct Node **forward;
} Node;

typedef struct SkipList {
    int level;
    struct Node* header;
} SkipList;

Node* createNode(int val, int level) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->val = val;
    nn->forward = (Node **)malloc(sizeof(Node *) * (level + 1));
    for (int i = 0; i <= level; i++) {
        nn->forward[i] = NULL;
    }
    return nn;
}

SkipList* createSkipList() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode(INT_MIN, SKIPLIST_MAX_LEVEL);
    return list;
}

int randomLevel() {
    int lvl = 0;
    while ((float)rand() / RAND_MAX < P && lvl < SKIPLIST_MAX_LEVEL) {
        lvl++;
    }
    return lvl;
}

void insert(SkipList* list, int val) {
    Node* update[SKIPLIST_MAX_LEVEL + 1];
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->val < val) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == NULL || current->val != val) {
        int lvl = randomLevel();

        if (lvl > list->level) {
            for (int i = list->level + 1; i <= lvl; i++) {
                update[i] = list->header;
            }
            list->level = lvl;
        }

        Node* newNode = createNode(val, lvl);

        for (int i = 0; i <= lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

Node* search(SkipList* list, int val) {
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->val < val) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];

    if (current != NULL && current->val == val) {
        return current;
    } else {
        return NULL;
    }
}

void delete(SkipList* list, int val) {
    Node* update[SKIPLIST_MAX_LEVEL + 1];
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->val < val) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL && current->val == val) {
        for (int i = 0; i <= list->level; i++) {
            if (update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }
        free(current->forward);
        free(current);

        while (list->level > 0 && list->header->forward[list->level] == NULL) {
            list->level--;
        }
    }
}

int main() {
    srand(time(NULL)); 

    SkipList* list = createSkipList();

    insert(list, 10);
    insert(list, 20);
    insert(list, 15);
    insert(list, 30);
    insert(list, 25);

    int to_search[] = {15, 100};
    for (int i = 0; i < 2; i++) {
        Node* res = search(list, to_search[i]);
        if (res != NULL) {
            printf("Found %d in skip list.\n", to_search[i]);
        } else {
            printf("%d not found in skip list.\n", to_search[i]);
        }
    }

    printf("Deleting 20...\n");
    delete(list, 20);

    Node* res = search(list, 20);
    if (res != NULL) {
        printf("Found 20 in skip list.\n");
    } else {
        printf("20 not found in skip list.\n");
    }

    return 0;
}
