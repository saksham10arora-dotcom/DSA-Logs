// 📘 Linked List – Creation and Traversal in C
// Author: Saksham Arora
// Source: Abdul Bari (Udemy) – Revision Notes
// Date: Oct 28, 2025

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
void RecDisplay(struct Node *p){
    if p!= NULL{
        printf("%d",p->data);
        RecDisplay(p->next);
    }
}
void RRDisplay(struct Node *p){
    if p!= NULL{
        RRDisplay(p->next);
        printf("%d",p->data);   
    }
}
int count(struct Node *p){
    c = 0;
    while p{
        c++;
        p = p->next;
        return c;
    }
}

int Rcount(struct Node *p){
    int c;
    if p{
        return 1+(Rcount(p->next));
            }
    else return 0;
}

int sum(struct Node*p){
    s = 0;
    while p{
        s = s+p->data;
        p = p->next;
        return s;
]
int Rsum(struct Node*p){
    if p{
        return p->data + Rsum(p->next);
    else{
        return 0;
    }
}
int max(struct Node*p){
    max = MIN_INT;
    while p{
        if (p->data > max){
            max = p->data;
            p = p->next;
    return max;
int Rmax(struct Node*p){
        if (p != NULL){
            return MIN_INT;
        }
        x = Rmax(p->next);
        if (x > p->data){
            return x;
        }else{
            return (p->data)
            }
Node*search(Node*p, int key){
    while p{
        if (p->data == key){
            return p;
        else{
            p = p->next;
        }
    return NULL;
        }
Node*Rsearch(struct Node*p,int key){
    if p == 0{
        return NULL;
    if (p->data == key){
        return (p);
    Rsearch(struct Node*p->next,key);}

Node*Isearch(struct Node*p, int key){    
    struct Node*q = NULL;
    while p{
        if (p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        q = p;
        p = p->next;
        }
    }

void insert(struct Node*p, int x, int pos){
    struct Node*t
    if (pos == 0){
    t = new Node();
    t->data = x;
    t->next = first;
    first = t;

    
        
    
            
    
    
        

              
            
      
        
int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};

    create(A, 8);
    printf("Linked List Elements: ");
    display(first);

    return 0;
}
