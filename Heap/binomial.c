#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BinomialNode {
    int key;
    int degree;
    struct BinomialNode* parent;
    struct BinomialNode* child;
    struct BinomialNode* sibling;
} BinomialNode;

BinomialNode* createNode(int key) {
    BinomialNode* node = (BinomialNode*)malloc(sizeof(BinomialNode));
    node->key = key;
    node->degree = 0;
    node->parent = node->child = node->sibling = NULL;
    return node;
}

BinomialNode* binomialLink(BinomialNode* y, BinomialNode* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
    return z;
}

BinomialNode* mergeRootLists(BinomialNode* h1, BinomialNode* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    BinomialNode* head = NULL;
    BinomialNode* tail = NULL;
    BinomialNode* a = h1;
    BinomialNode* b = h2;

    if (a->degree <= b->degree) {
        head = a;
        a = a->sibling;
    } else {
        head = b;
        b = b->sibling;
    }
    tail = head;

    while (a && b) {
        if (a->degree <= b->degree) {
            tail->sibling = a;
            a = a->sibling;
        } else {
            tail->sibling = b;
            b = b->sibling;
        }
        tail = tail->sibling;
    }

    tail->sibling = (a) ? a : b;
    return head;
}

BinomialNode* unionHeaps(BinomialNode* h1, BinomialNode* h2) {
    BinomialNode* newHead = mergeRootLists(h1, h2);
    if (!newHead) return NULL;

    BinomialNode* prev = NULL;
    BinomialNode* curr = newHead;
    BinomialNode* next = curr->sibling;

    while (next) {
        if ((curr->degree != next->degree) || 
            (next->sibling && next->sibling->degree == curr->degree)) {
            prev = curr;
            curr = next;
        } else {
            if (curr->key <= next->key) {
                curr->sibling = next->sibling;
                binomialLink(next, curr);
            } else {
                if (!prev) {
                    newHead = next;
                } else {
                    prev->sibling = next;
                }
                binomialLink(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return newHead;
}

BinomialNode* insert(BinomialNode* heap, int key) {
    BinomialNode* newNode = createNode(key);
    return unionHeaps(heap, newNode);
}

BinomialNode* findMinNode(BinomialNode* heap) {
    if (!heap) return NULL;

    BinomialNode* y = NULL;
    BinomialNode* x = heap;
    int min = INT_MAX;

    while (x) {
        if (x->key < min) {
            min = x->key;
            y = x;
        }
        x = x->sibling;
    }
    return y;
}

BinomialNode* reverseList(BinomialNode* node) {
    BinomialNode* prev = NULL;
    BinomialNode* next;
    while (node) {
        node->parent = NULL;
        next = node->sibling;
        node->sibling = prev;
        prev = node;
        node = next;
    }
    return prev;
}

BinomialNode* extractMin(BinomialNode** heap) {
    if (!*heap) return NULL;

    BinomialNode* prevMin = NULL;
    BinomialNode* minNode = *heap;
    BinomialNode* prev = NULL;
    BinomialNode* curr = *heap;
    int min = curr->key;

    while (curr) {
        if (curr->key < min) {
            min = curr->key;
            prevMin = prev;
            minNode = curr;
        }
        prev = curr;
        curr = curr->sibling;
    }

    if (!prevMin) {
        *heap = minNode->sibling;
    } else {
        prevMin->sibling = minNode->sibling;
    }

    BinomialNode* childHeap = reverseList(minNode->child);
    *heap = unionHeaps(*heap, childHeap);

    return minNode;
}

BinomialNode* findNode(BinomialNode* root, int key) {
    if (!root) return NULL;
    if (root->key == key) return root;

    BinomialNode* res = findNode(root->child, key);
    if (res) return res;
    return findNode(root->sibling, key);
}

int decreaseKey(BinomialNode* heap, int oldKey, int newKey) {
    if (newKey > oldKey) {
        printf("New key is greater than current key\n");
        return -1;
    }

    BinomialNode* node = findNode(heap, oldKey);
    if (!node) {
        printf("Key not found\n");
        return -1;
    }

    node->key = newKey;
    BinomialNode* y = node;
    BinomialNode* z = y->parent;

    while (z && y->key < z->key) {
        int temp = y->key;
        y->key = z->key;
        z->key = temp;

        y = z;
        z = y->parent;
    }
    return 0;
}

void printHeap(BinomialNode* heap) {
    if (!heap) {
        printf("Empty heap\n");
        return;
    }
    printf("Binomial Heap:\n");
    BinomialNode* curr = heap;
    while (curr) {
        printf("B%d\n", curr->degree);
        printTree(curr, 0);
        curr = curr->sibling;
    }
}

void printTree(BinomialNode* root, int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
    printf("%d\n", root->key);
    BinomialNode* child = root->child;
    while (child) {
        printTree(child, indent + 1);
        child = child->sibling;
    }
}

int main() {
    BinomialNode* heap = NULL;

    heap = insert(heap, 10);
    heap = insert(heap, 20);
    heap = insert(heap, 15);
    heap = insert(heap, 30);
    heap = insert(heap, 5);

    printHeap(heap);

    BinomialNode* minNode = findMinNode(heap);
    if (minNode)
        printf("Minimum key: %d\n", minNode->key);

    BinomialNode* extracted = extractMin(&heap);
    if (extracted) {
        printf("Extracted min: %d\n", extracted->key);
        free(extracted);
    }

    printHeap(heap);

    printf("Decrease key 20 to 2\n");
    decreaseKey(heap, 20, 2);
    printHeap(heap);
}

