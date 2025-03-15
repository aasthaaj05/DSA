#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, Node* treeNode) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = stack->top;
    stack->top = newStackNode;
}

Node* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    StackNode* temp = stack->top;
    Node* treeNode = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
    return treeNode;
}

void inorder_itr(Node* t) {
    Stack s;
    initStack(&s);
    while (t != NULL) {
        push(&s, t);
        t = t->left;
    }
    while (!isEmpty(&s)) {
        t = pop(&s);    
        printf("%d ", t->data);  
        
        t = t->right;  
        while (t != NULL) {
            push(&s, t);
            t = t->left;
        }
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
        return;
    }
}

void preorder_itr(Node* t) {
    Stack s;
    initStack(&s);
    while (t != NULL) {
    	printf("%d ", t->data);  
        push(&s, t);
        t = t->left;
    }
    while (!isEmpty(&s)) {
        t = pop(&s);    
        t = t->right;  
        while (t != NULL) {
            printf("%d ", t->data);  
            push(&s, t);
            t = t->left;
        }
    }
}

void preorder(Node* root){
	if(root==NULL) return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder_itr(Node*t){
	Stack s0,s1;
	Node* t1;
        initStack(&s0);
        initStack(&s1);
        while (t != NULL) {
		push(&s0, t);
		push(&s1,NULL);
		t = t->left;
        }
        while(!isEmpty(&s1)){
        	t=pop(&s0);
        	t1=pop(&s1);
        	if(t1==NULL){
        		push(&s0, t);
        		push(&s1, (Node*)1);
        		t=t->right;
        		while (t != NULL) {
				push(&s0, t);
				push(&s1,NULL);
				t = t->left;
		       }
        		
        	}else{
        		printf("%d ", t->data);
        	}
        }
                
}

void postorder(Node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    printf("Inorder (Iterative):\n");
    inorder_itr(root);
    printf("\n");
    
    printf("Inorder (Recursive):\n");
    inorder(root);
    printf("\n");

    printf("Preorder (Iterative):\n");
    preorder_itr(root);
    printf("\n");
    
    printf("Preorder (Recursvive):\n");
    preorder(root);
    printf("\n");

    printf("Postorder (Iterative):\n");
    postorder_itr(root);
    printf("\n");
    
    printf("Postorder (Recursive):\n");
    postorder(root);
    printf("\n");

    return 0;
}


