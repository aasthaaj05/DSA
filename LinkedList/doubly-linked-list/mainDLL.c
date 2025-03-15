#include <stdio.h>
#include "doublyLL.h"

int main() {
    DLL L1;

    // Initialize the list
    init(&L1);

    // Insert at the beginning
    insert_beg(&L1, 10);
    insert_beg(&L1, 20);
    insert_beg(&L1, 30);

    // Insert at the end
    append(&L1, 40);
    append(&L1, 50);

    // Display list from left to right
    printf("List from Left to Right:\n");
    printLToR(L1);

    // Insert at a specific position
    insert_pos(&L1, 25, 3);  // Insert 25 at position 3
    printf("List after inserting 25 at position 3 :\n");
    printLToR(L1);

    // Display list from right to left
    printf("List from Right to Left:\n");
    printRToL(L1);

    // Check if the list is a palindrome
    printf("Checking if the list is a palindrome:\n");
    isPalindrome(&L1);

    // Remove from the beginning
    remove_beg(&L1);
    printf("List after removing from the beginning:\n");
    printLToR(L1);

    // Remove from the end
    remove_end(&L1);
    printf("List after removing from the end :\n");
    printLToR(L1);

    // Remove from a specific position
    remove_pos(&L1, 2); 
    printf("List after removing element at position 2 :\n");
    printLToR(L1);

    return 0;
}

