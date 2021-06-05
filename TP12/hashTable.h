#include "node.h"

typedef struct hashTable{
    int size;
    int number_word;
    Node** list;
}HashTable;

HashTable* create_table(int size);
void free_hash(HashTable *h);

int hash(char* word, int n);

Node* find(Node* t, char* str);
HashTable* add_to_hash(HashTable* h, char* str);