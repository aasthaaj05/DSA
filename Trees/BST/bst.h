typedef struct Node {
    char month[20];  
    int monthNum;    
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Node* BST;

typedef struct StackNode {
    Node* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void initBST(BST* t);
void insertNode(BST* t, char* month, int monthNum);
BST removeNode(BST root, int monthNum);
void inorderTraverse(BST t);
void destroyTree(BST* t);
Node* findMin(Node* node);
void push(Stack* s, Node* data);
Node* pop(Stack* s);
