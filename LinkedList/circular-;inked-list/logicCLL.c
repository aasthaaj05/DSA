#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "clist.h"

int isEmpty(list l) {
    return l == NULL;
}

void init(list *l) {
    *l = NULL;
}

void traverse(list head) {
    if (isEmpty(head)) {
        return;
    }
    Node* temp = head;
    printf("%d", head->data);  
    temp = temp->next;
    while (temp != head) {  
        printf(" -> %d", temp->data);
        temp = temp->next;
    }
    printf(" -> (head)\n");
}

int count(list l) {
    if (isEmpty(l)) {
        return 0;
    }
    int cnt = 1;
    Node* p = l;
    while (p->next != l) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void append(list *l, int d) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = d;
    if (isEmpty(*l)) {
        *l = nn;
        nn->next = *l; 
        return;
    }
    Node *temp = *l;
    while (temp->next != *l) {
        temp = temp->next;
    }
    temp->next = nn;
    nn->next = *l;  
}

void insert_at_beg(list *l, int d) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = d;
    if (isEmpty(*l)) {
        *l = nn;
        nn->next = *l;
        return;
    }
    Node* temp = *l;
    while (temp->next != *l) {
        temp = temp->next;
    }
    nn->next = *l;
    temp->next = nn;
    *l = nn;  
}

void insert_at_pos(list *l, int data, int pos) {
    if (pos == 1) {
        insert_at_beg(l, data);
    } else if (pos > count(*l)) {
        append(l, data);
    } else {
        Node* nn = (Node*)malloc(sizeof(Node));
        nn->data = data;
        Node* temp = *l;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
}

void remove_beg(list *l) {
    if (isEmpty(*l)) {
        return;
    }
    Node* temp = *l;
    if (temp->next == *l) {  
        free(temp);
        *l = NULL;
    } else {
        Node* last = *l;
        while (last->next != *l) {
            last = last->next;
        }
        Node* new_head = temp->next;
        last->next = new_head;
        free(temp);
        *l = new_head;  
    }
}

void remove_end(list *l) {
    if (isEmpty(*l)) {
        return;
    }
    Node* temp = *l;
    if (temp->next == *l) {  
        free(temp);
        *l = NULL;
    } else {
        Node* prev = NULL;
        while (temp->next != *l) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *l;  
        free(temp);
    }
}

void remove_pos(list *l, int pos) {
    if (pos == 1) {
        remove_beg(l);
    } else if (pos == count(*l)) {
        remove_end(l);
    } else {
        Node* temp = *l;
        Node* prev = NULL;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void sort(list* head) {
    if (isEmpty(*head)) {
        return;
    }
    Node* current = *head;
    Node* index = NULL;
    int temp;

    do {
        index = current->next;
        while (index != *head) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current != *head);
}

