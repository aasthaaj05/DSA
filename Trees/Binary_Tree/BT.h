/*
Implement ADT Binary Tree Using Linked List.

Include the following functions :

1. init_bt()

2. insert() //recursive

3. recursive_traverse() // inorder,preorder,postorder

4. count_leaf() //recursive function to count the leaf nodes in BST

5. count_nonleaf()  //recursive function to count the non-leaf nodes in BST
*/

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Node* BT;

void init(BT* t);
BT insert(BT t, int d);
void inorder(BT t);
int count_leaf(BT t);
int count_nonleaf(BT t); 
