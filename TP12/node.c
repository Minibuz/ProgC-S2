#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Node *create_node(char* word){
    Node *node = (Node*)malloc(sizeof(Node));
    node->word = malloc(strlen(word)+1);
    strcpy(node->word,word);
    node->node = NULL;
    return node;
}

void free_node(Node *n) {
    free(n->word);
    free(n);
}

void free_nodes(Node *n) {
    while(n) {
        Node *tmp = n;
        n=n->node;
        free_node(tmp);
    }
}

int equal(char* word1, char* word2) {
    return strcmp(word1,word2) == 0;
}

/**
 * Return 1 if the word is in the List,
 * Return 0 otherwise
 */
int find_word(Node *n,char* word) {
    Node *tmp = n;
    while(tmp!=NULL && !equal(tmp->word,word)) {
        tmp = tmp->node;
    }
    
    if(tmp == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int size_node(Node *n) {
    if(n==NULL){
        return -1;
    }
    return size_node(n->node);
}


Node *insert_front(Node *n, char* word) {
    Node* new = create_node(word);
    new->node = n;
    return new;
}