// 📘 Linked List – Creation and Traversal in C
// Author: Saksham Arora
// Source: Abdul Bari (Udemy) – Revision Notes
// Date: Oct 28, 2025

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

// Global pointer to first node
struct Node *first = NULL;

// ------------------------------------------
// 🧩 Function: create
// Creates a linked list from an array
// ------------------------------------------
void create(int A[], int n) {
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// ------------------------------------------
// 🔁 Function: display
// Traverses through the linked list and prints all elements
// ------------------------------------------
void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ------------------------------------------
// 🧠 main function
// ------------------------------------------
int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};

    create(A, 8);
    printf("Linked List Elements: ");
    display(first);

    return 0;
}
