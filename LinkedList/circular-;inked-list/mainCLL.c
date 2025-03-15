#include <stdio.h>
#include "clist.h"

int main() {
    list L1;  // Define the circular linked list (CLL)
    
    // Initialize the list
    init(&L1);
    
    // Insert at the beginning
    insert_at_beg(&L1, 10);
    insert_at_beg(&L1, 20);
    insert_at_beg(&L1, 30);

    // Insert at the end
    append(&L1, 40);
    append(&L1, 50);

    // Display the list
    printf("List after inserting at beginning and end:\n");
    traverse(L1);

    // Insert at a specific position
    insert_at_pos(&L1, 25, 3);  // Insert 25 at position 3
    printf("\nList after inserting 25 at position 3:\n");
    traverse(L1);

    // Remove from the beginning
    remove_beg(&L1);
    printf("\nList after removing from the beginning:\n");
    traverse(L1);

    // Remove from the end
    remove_end(&L1);
    printf("\nList after removing from the end:\n");
    traverse(L1);

    // Remove from a specific position
    remove_pos(&L1, 2);  // Remove the node at position 2
    printf("\nList after removing element at position 2:\n");
    traverse(L1);

    // Sort the list
    sort(&L1);
    printf("\nList after sorting:\n");
    traverse(L1);

    return 0;
}

