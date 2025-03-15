#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void initBST(BST* t) {
    *t = NULL;  
}

void insertNode(BST* t, char* month, int monthNum) {
    Node* nn = (Node*)malloc(sizeof(Node));
    strcpy(nn->month, month);
    nn->monthNum = monthNum;
    nn->left = NULL;
    nn->right = NULL;
    if (*t == NULL) {  
        *t = nn;  
        return;
    }
    Node* current = *t;  
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (monthNum < current->monthNum) {  
            current = current->left;
        } else if (monthNum > current->monthNum) {  
            current = current->right;
        } else {  
            free(nn);
            return;
        }
    }
    if (monthNum < parent->monthNum) {
        parent->left = nn;
    } else {
        parent->right = nn;
    }
}

Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

BST removeNode(BST root, int monthNum) {
    if (root == NULL) return root;
    if (monthNum < root->monthNum) {
        root->left = removeNode(root->left, monthNum);
    } else if (monthNum > root->monthNum) {
        root->right = removeNode(root->right, monthNum);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        strcpy(root->month, temp->month);  
        root->monthNum = temp->monthNum;
        root->right = removeNode(root->right, temp->monthNum); 
    }
    return root;
}

void initStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, Node* data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

Node* pop(Stack* s) {
    if (s->top == NULL) return NULL;
    StackNode* temp = s->top;
    Node* node = temp->data;
    s->top = s->top->next;
    free(temp);
    return node;
}

int isEmpty(Stack* s) {
    if(s->top == NULL) return 1;
    return 0;
}

void inorderTraverse(BST t) {
    Stack s;
    initStack(&s);
    Node* current = t;
    while (current != NULL || !isEmpty(&s)) {
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);
        printf("%s ", current->month); 
        current = current->right;
    }
}

void destroyTree(BST* t) {
    if (*t == NULL) return;
    destroyTree(&((*t)->left));
    destroyTree(&((*t)->right));
    free(*t);
    *t = NULL;
}


/*

// Function to find the leftmost node (used for right subtree case)
BST findLeftmost(BST node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

// Non-recursive function to find the inorder successor of a node
BST findInorderSuccessor(BST root, BST target) {
    BST successor = NULL;

    while (root != NULL) {
        if (target->data < root->data) {
            // Potential successor found, go left
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            // Go right
            root = root->right;
        } else {
            // Node found
            if (target->right != NULL) {
                // Case 1: Right subtree exists, find the leftmost node
                return findLeftmost(target->right);
            }
            break;
        }
    }

    // Case 2: No right subtree, return the last recorded successor
    return successor;
}

// Function to convert the sorted array back into the Min-Heap (Level-Order)
void arrayToMinHeap(Node* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }

    // First process the left child, then root, and finally right child (Level-order)
    root->data = arr[*index];
    (*index)++;

    arrayToMinHeap(root->left, arr, index);  // Process left subtree
    arrayToMinHeap(root->right, arr, index); // Process right subtree
}

// Function to convert the BST to a Min-Heap
void bstToMinHeap(Node* root) {
    if (root == NULL) {
        return;
    }

    int* arr = (int*)malloc(100 * sizeof(int)); // Array to store the in-order traversal
    int index = 0;

    // Step 1: Perform in-order traversal and store nodes in the array
    inorder(root, arr, &index);

    // Step 2: Convert the sorted array back to a Min-Heap
    index = 0;
    arrayToMinHeap(root, arr, &index);

    // Free the allocated memory for the array
    free(arr);
}

*/
