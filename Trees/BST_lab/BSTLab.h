/*
mplement ADT Binary Search Tree Using an Array.

Include the following functions :

1. init_bst()

2. insert() //recursive

3. recursive_traverse() // inorder,preorder,postorder

4. count_leaf() //non-recursive function to count the leaf nodes in BST

5. count_nonleaf()  //non-recursive function to count the non-leaf nodes in BST

6. height() // both recursive and non recursive
*/

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Node* BST;

void init(BST* t);
BST insert(BST t, int d);
void inorder(BST t);
int count_leaf(BST t);
int count_nonleaf(BST t); 
int heightITR(BST t);
int heightRecursive(BST t);
