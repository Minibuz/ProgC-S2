#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("./Germinal.txt","r");
    if(file == NULL) {
        fprintf(stderr,"Error");
        return 1;
    }

    HashTable *tab = create_table(4096);
    char *word = (char *)malloc(80*sizeof(char));
    while(fscanf(file,"%s ",word)!=-1) {
        tab = add_to_hash(tab,word);
    }
    free(word);
    fclose(file);

    printf("%d different words found in Germinal\n",tab->number_word);
    free_hash(tab);
    return 0;
}