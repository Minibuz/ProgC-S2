#include "hashTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

HashTable* create_table(int size) {
    HashTable *h = (HashTable*)malloc(sizeof(HashTable));
    h->size = size;
    h->number_word = 0;

    h->list = (Node**)malloc(sizeof(Node)*size);
    int i = 0;
    for(i = 0; i<size; i++) {
        h->list[i] = NULL;
    }

    return h;
}

void free_hash(HashTable *h) {
    int i = 0;
    for(i=0;i<h->size;i++) {
        free_nodes(h->list[i]);
    }
    free(h->list);
    free(h);
}

int hash(char word[], int n) {
    unsigned count = 0;
    int i = 0;
    for(i=0; word[i]!='\0'; i++) {
        count += (i+1) * word[i];
    }
    return count %= n;
}

Node* find(Node* t, char* str) {
    Node* tmp = t;
    while(tmp!=NULL && !equal(tmp->word,str)) {
        tmp = tmp->node;
    }
    return tmp;
}

HashTable* add_to_hash(HashTable* h, char* str) {
    int index = hash(str,h->size);
    Node** list = h->list;
    Node* n = find(list[index], str);
    if(n==NULL) {
        list[index] = insert_front(list[index], str);
        h->number_word++;
    }
    return h;
}