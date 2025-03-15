#include<stdio.h>
#include<stdlib.h>
#include"BSTLab.h"

void init(BST* t){
	*t=NULL;
}

BST insert(BST t, int d){
	if(t==NULL){
		Node* nn=(Node*)malloc(sizeof(Node));
		nn->val=d;
		nn->left=NULL;
		nn->right=NULL;
		return nn;
	}
	if(d>t->val){
		t->right=insert(t->right,d);
	}else if(d<t->val){
		t->left=insert(t->left,d);
	}
	return t;
}


BST insert(BST t, int d) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->val = d;
    nn->left = NULL;
    nn->right = NULL;

    // If the tree is empty, the new node becomes the root
    if (t == NULL) {
        return nn;
    }

    Node* parent = NULL;
    Node* current = t;

    // Traverse the tree to find the insertion point
    while (current != NULL) {
        parent = current;
        if (d < current->val) {
            current = current->left;
        } else if (d > current->val) {
            current = current->right;
        } else {
            // Duplicate value, no need to insert
            free(nn);
            return t;
        }
    }

    // Insert the new node as a child of the found parent node
    if (d < parent->val) {
        parent->left = nn;
    } else {
        parent->right = nn;
    }

    return t;
}

void inorder(BST t){
	if(t==NULL) return;
	inorder(t->left);
	printf("%d	",t->val);
	inorder(t->right);
}

int count_leaf(BST t){
    if (t == NULL) return 0;
    int count = 0;
    Node* queue[100];  
    int front = 0, rear = 0;
    queue[rear++] = t;
    while (front < rear) {
        Node* temp = queue[front++];
        if (temp->left == NULL && temp->right == NULL) {
            count++;
        }
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
    return count;
}

int count_nonleaf(BST t) {
    if (t == NULL) return 0;
    int count = 0;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = t;
    while (front < rear) {
        Node* temp = queue[front++];
        if (temp->left != NULL || temp->right != NULL) {
            count++;
        }
        if (temp->left != NULL) queue[rear++] = temp->left;
        if (temp->right != NULL) queue[rear++] = temp->right;
    }
    return count;
}

int heightITR(BST t){
	if (t == NULL) return 0;
	Node* temp;
	int ht=0;
	Node* queue[100];
	int f=-1, r=-1;
	queue[++r]=t;
	while (f != r) {
		int nodeCount = r - f; 
		while (nodeCount > 0) {
		    temp = queue[++f];
		    if (temp->left != NULL) {
		        queue[++r] = temp->left;
		    }
		    if (temp->right != NULL) {
		        queue[++r] = temp->right;
		    }
		    nodeCount--;
		}
		ht++;
	}
	return ht;
}

int heightRecursive(BST t){
	if (t == NULL) return 0;
	int left=heightRecursive(t->left);
	int right=heightRecursive(t->right);
	if(left>right){
		return left+1;
	}else{
		return right+1;
	}
}

