#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    long timestamp;       // sorting key
    struct Node* left;
    struct Node* parent;
    struct Node* right;
    int color; // red=1, black=0
} Node;

Node* createNode(int val, long timestamp) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->val = val;
    nn->timestamp = timestamp;
    nn->color = 1; // new node red by default
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    return nn;
}

Node* rightRotate(Node* root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;

    return root;
}

Node* leftRotate(Node* root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    return root;
}

Node* insert(Node* root, int val, long timestamp) {
    Node* z = createNode(val, timestamp);
    Node* y = NULL;
    Node* x = root;

    // Insert based on timestamp (sort key)
    while (x != NULL) {
        y = x;
        if (z->timestamp < x->timestamp)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (z->timestamp < y->timestamp)
        y->left = z;
    else
        y->right = z;

    // Fix Red-Black Tree properties
    while (z != root && z->parent->color == 1) {
        if (z->parent == z->parent->parent->left) {
            Node* uncle = z->parent->parent->right;
            if (uncle != NULL && uncle->color == 1) {
                // Case 1
                z->parent->color = 0;
                uncle->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    // Case 2
                    z = z->parent;
                    root = leftRotate(root, z);
                }
                // Case 3
                z->parent->color = 0;
                z->parent->parent->color = 1;
                root = rightRotate(root, z->parent->parent);
            }
        } else {
            Node* uncle = z->parent->parent->left;
            if (uncle != NULL && uncle->color == 1) {
                // Case 1
                z->parent->color = 0;
                uncle->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    // Case 2
                    z = z->parent;
                    root = rightRotate(root, z);
                }
                // Case 3
                z->parent->color = 0;
                z->parent->parent->color = 1;
                root = leftRotate(root, z->parent->parent);
            }
        }
    }

    root->color = 0; // root is always black
    return root;
}

// Search by timestamp key
Node* search(Node* root, long timestamp) {
    while (root != NULL && root->timestamp != timestamp) {
        if (timestamp < root->timestamp)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Val: %d, Timestamp: %ld, Color: %s\n",
               root->val, root->timestamp,
               root->color == 1 ? "Red" : "Black");
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Example data with (value, timestamp)
    int vals[] = {10, 20, 30, 15, 25, 5, 1};
    long timestamps[] = {1005, 1002, 1010, 1003, 1008, 1001, 999};
    int n = sizeof(vals) / sizeof(vals[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, vals[i], timestamps[i]);
    }

    printf("Inorder traversal (sorted by timestamp):\n");
    inOrder(root);

    // Searching for timestamp
    long ts = 1003;
    Node* found = search(root, ts);
    if (found)
        printf("\nFound node with timestamp %ld: val = %d, color = %s\n",
               ts, found->val, found->color == 1 ? "Red" : "Black");
    else
        printf("\nNode with timestamp %ld not found.\n", ts);

    return 0;
}
