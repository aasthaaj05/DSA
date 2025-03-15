#include<stdio.h>
#include<stdlib.h>
#include"BT.h"

int main() {
    BT root;
    init(&root);

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    inorder(root);

    int leaf_count = count_leaf(root);
    int nonleaf_count = count_nonleaf(root);

    printf("Number of leaf nodes: %d\n", leaf_count);
    printf("Number of non-leaf nodes: %d\n", nonleaf_count);

    return 0;
}

