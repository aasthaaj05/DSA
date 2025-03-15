#include"poly.h"
#include<stdio.h>
#include<stdlib.h>

void init(poly* p, int size) {
    p->n = 0;  // Start with zero terms
    p->t = (term*)malloc(sizeof(term) * size);
}

void append(poly* p, int c, int e) {
    p->t[p->n].c = c;
    p->t[p->n].e = e;
    p->n++;  // Increase the number of terms after appending
}

void display(poly* p) {
    int i;
    for (i = 0; i < p->n; i++) {
        if (i != 0 && p->t[i].c > 0) printf("+");
        printf("%dx^%d ", p->t[i].c, p->t[i].e);
    }
    printf("\n");
}

void add_poly(poly* p, poly* q, poly* result) {
    int i = 0, j = 0, k = 0;
    while (i < p->n && j < q->n) {
        if (p->t[i].e > q->t[j].e) {
            result->t[k++] = p->t[i++];
        } else if (p->t[i].e < q->t[j].e) {
            result->t[k++] = q->t[j++];
        } else {
            result->t[k].e = p->t[i].e;
            result->t[k].c = p->t[i].c + q->t[j].c;
            i++;
            j++;
            k++;
        }
    }
    while (i < p->n) {
        result->t[k++] = p->t[i++];
    }
    while (j < q->n) {
        result->t[k++] = q->t[j++];
    }
    result->n = k;
}

void sub_poly(poly* p, poly* q, poly* result) {
    int i = 0, j = 0, k = 0;
    while (i < p->n && j < q->n) {
        if (p->t[i].e > q->t[j].e) {
            result->t[k++] = p->t[i++];
        } else if (p->t[i].e < q->t[j].e) {
            result->t[k].e = q->t[j].e;
            result->t[k].c = -q->t[j].c;
            j++;
            k++;
        } else {
            result->t[k].e = p->t[i].e;
            result->t[k].c = p->t[i].c - q->t[j].c;
            i++;
            j++;
            k++;
        }
    }
    while (i < p->n) {
        result->t[k++] = p->t[i++];
    }
    while (j < q->n) {
        result->t[k].e = q->t[j].e;
        result->t[k].c = -q->t[j].c;
        j++;
        k++;
    }
    result->n = k;
}
