#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

Head* createHead() {
    Head* head = (Head*) malloc (sizeof(Head));
    head->firstElement = NULL;
    head->size = 0;
    return head;
}

Stack* createStack(int value) {
    Stack* stack = (Stack*) malloc (sizeof(Stack));
    stack->value = value;
    stack->next = NULL;
    return stack;
}

void freeStack(Head* h) {
    while(h->firstElement != NULL) {
        Stack* tmp = h->firstElement;
        h->size--;
        h->firstElement = h->firstElement->next;
        free(tmp);
    }
}

int stackSize(Head* h) {
    return h->size;
}



void push(Head* currentHead,int value) {
    Stack* new = createStack(value);
    new->next = currentHead->firstElement;
    currentHead->firstElement = new;
    currentHead->size++;
}

int pop(Head* currentHead) {
    Stack* old = currentHead->firstElement;
    currentHead->firstElement = old->next;
    currentHead->size--;
    int value = old->value;
    free(old);
    return value;
}

void reverse(Head* currentHead) {
    Stack* tmp = currentHead->firstElement;
    currentHead->firstElement = tmp->next;
    tmp->next = currentHead->firstElement->next;
    currentHead->firstElement->next = tmp;
}



void printHead(Head* h) {
    printf("Value at head of stack : %d\n", h->firstElement->value);
}

void printWholeStack(Head* h) {
    Stack* tmp = h->firstElement;
    printf("Stack currently :\n");
    while(tmp!=NULL) {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
    printf("End of stack.\n");
}