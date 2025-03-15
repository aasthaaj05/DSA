#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int getMonthNum(char* month) {
    if (strcmp(month, "January") == 0) return 1;
    if (strcmp(month, "February") == 0) return 2;
    if (strcmp(month, "March") == 0) return 3;
    if (strcmp(month, "April") == 0) return 4;
    if (strcmp(month, "May") == 0) return 5;
    if (strcmp(month, "June") == 0) return 6;
    if (strcmp(month, "July") == 0) return 7;
    if (strcmp(month, "August") == 0) return 8;
    if (strcmp(month, "September") == 0) return 9;
    if (strcmp(month, "October") == 0) return 10;
    if (strcmp(month, "November") == 0) return 11;
    if (strcmp(month, "December") == 0) return 12;
    return -1;  
}

void printMenu() {
    printf("\n\nBinary Search Tree Operations:\n");
    printf("1. Insert a month\n");
    printf("2. Remove a month\n");
    printf("3. In-order Traversal\n");
    printf("4. Destroy Tree\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    BST tree;
    initBST(&tree);

    int choice;
    char month[20];

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the month to insert: ");
                scanf("%s", month);
                int monthNum = getMonthNum(month);
                if (monthNum == -1) {
                    printf("Invalid \n");
                } else {
                    insertNode(&tree, month, monthNum);
                    printf("Inserted %s into the tree.\n", month);
                }
                break;

            case 2:
                printf("Enter the month to remove: ");
                scanf("%s", month);
                monthNum = getMonthNum(month);
                if (monthNum == -1) {
                    printf("Invalid month!\n");
                } else {
                    tree = removeNode(tree, monthNum);
                    printf("Removed %s from the tree (if it existed).\n", month);
                }
                break;

            case 3:
                printf("In-order Traversal: ");
                inorderTraverse(tree);
                printf("\n");
                break;

            case 4:
                destroyTree(&tree);
                printf("Destroyed\n");
                break;

            case 5:
                break;

            default:
                printf("Invalid\n");
        }
    } while (choice != 5);

    return 0;
}

