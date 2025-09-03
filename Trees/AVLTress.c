#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
	int height;
}Node;

Node* createNode(int val){
	Node* nn=(Node*)malloc(sizeof(Node));
	nn->val=val;
	nn->left=NULL;
	nn->right=NULL;
	nn->height=1;
	return nn;
}

int max(int a, int b){ return (a>b) ? a : b; }

int getHeight(Node* root){
	if(root==NULL) return 0;
	return root->height;
}

int getBalanceFactor(Node* n){
    if(n==NULL)
        return 0;
    return getHeight(n->left)-getHeight(n->right);
}

Node* rightRotate(Node* y){
	Node* x=y->left;
	Node* temp=x->right;
	
	x->right=y;
    	y->left=temp;
    	
	y->height=max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height=max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}

Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height=max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int val){
    if(node==NULL) return createNode(val);
    if(val < node->val)
        node->left = insert(node->left, val);
    else if(val > node->val)
        node->right = insert(node->right, val);
    else 
        return node;
        
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->val);
        inOrder(root->right);
    }
}

int main(){
    Node* root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    printf("Inorder traversal of AVL tree: ");
    inOrder(root);

}
