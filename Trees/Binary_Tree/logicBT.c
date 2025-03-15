/*
typedef struct NOde{
	int val;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Node* BT;
*/

#include<stdio.h>
#include<stdlib.h>
#include"BT.h"

void init(BT* t){
	*t=NULL;
}

BT insert(BT t, int d) {
    if (t == NULL) {
        Node* nn = (Node*)malloc(sizeof(Node));
        nn->val = d;
        nn->left = nn->right = NULL;
        t=nn;
        return t;
    }
    if (t->left == NULL) {
        t->left = insert(t->left, d);
    }else if(t->right==NULL) {
        t->right = insert(t->right, d);
    }else{
    	t->left = insert(t->left, d);	
    }
    return t;
}

void inorder(BT t){
	if(t==NULL) return;
	inorder(t->left);
	printf("%d	",t->val);
	inorder(t->right);
}

int count_leaf(BT t){
	if(t==NULL) return 0;
	if(t->left==NULL && t->right==NULL) return 1;
	return count_leaf(t->left)+count_leaf(t->right);
}

int count_nonleaf(BT t){
	if(t==NULL||(t->left==NULL && t->right==NULL)) return 0;
	return 1 + count_nonleaf(t->left) + count_nonleaf(t->right);
} 

/*
// Recursive function to find the maximum element in the tree
int findMax(Node* root) {
    if (root == NULL) {
        return INT_MIN; // If tree is empty, return the smallest possible value
    }

    // Recursively find the max in the left and right subtrees
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    // Return the maximum of the current node's data, leftMax, and rightMax
    int res;
    if(root->data > leftMax){
    	if(root->data > rightMax){
    		return root->data;
    	}
    	return rightMax;
    }else{
    	if(leftMax > rightMax){
    		return leftMax;
    	}
    	return rightMax;
    }


// Helper function to check if the tree is a BST
int isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) {
        return 1;  // An empty tree is a BST
    }

    // Check the current node's data
    if (root->data <= min || root->data >= max) {
        return 0;  // Not a BST if the current node violates the min/max constraint
    }

    // Recursively check the left and right subtrees with updated constraints
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

// Function to check if the tree is a BST
int isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
}
*/




