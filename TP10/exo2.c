#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* file = fopen("liste_nom.txt","rt");
    if(file == NULL) {
        fprintf(stderr, "File doesn't exist.\n");
        exit(1);
    }

    List list = NULL;
    char line[81];
    while(!feof(file)) {
        char* first = (char*) malloc(sizeof(char) * 80);
        char* last = (char*) malloc(sizeof(char) * 80);
        int age;
        fscanf(file, "%80s", first);
        fscanf(file, "%80s", last);
        fscanf(file, "%d", &age);

        Cell* newCell = allocate_cell(first, last, age);
        list = ordered_insertion(list,newCell,age_order);
    }
    fclose(file);

    print_list(list);
    free_list(list);

    return 0;
}