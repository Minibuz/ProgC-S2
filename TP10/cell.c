#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cell* allocate_cell(char* first, char* last, int age) {
    Cell* new_cell = (Cell*)malloc(sizeof(Cell));
    if(new_cell == NULL) {
        fprintf(stderr,"Error : Not enough Memory\n");
        exit(1);
    }
    new_cell->first_name = first;
    new_cell->last_name = last;
    new_cell->age = age;
    return new_cell;
}

void free_cell(Cell* c) {
    free(c->first_name);
    free(c->last_name);
    free(c);
}

void free_list(List l) {
    List tmp = l;
    if(l!=NULL) {
        tmp=l->next;
        free_cell(l);
        free_list(tmp);
    }
}



int age_order(Cell* p1, Cell* p2) {
    if(p1->age < p2->age) {
        return 0;
    } else if(p1->age == p2->age) {
        return name_order(p1,p2);
    }
    return 1;
}

int name_order(Cell* p1, Cell* p2) {
    int last = strcmp(p1->last_name,p2->last_name);

    if(last>0) {
        return 1;
    } else if(last == 0) {
        int first = strcmp(p1->first_name,p2->first_name);
        if(first>0) {
            return 1;
        } else if(first == 0) {
            if(p1->age < p2->age) {
                return 0;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

List ordered_insertion(List l, Cell* newCell, int f(Cell*, Cell*)) {
    if(newCell == NULL) {
        return l;
    }
    if(l == NULL) {
        newCell->next = NULL;
        l = newCell;
        return l;
    }

    Cell* tmp = l;
    if(f(l, newCell) == 1) {
        newCell->next = tmp;
        l = newCell;
        return l;
    }
    while(tmp->next != NULL) {
        if(f(l, newCell) == 1) {
            newCell->next = tmp->next;
            tmp->next = newCell;
            return l;
        }
        tmp = tmp->next;
    }
    tmp->next = newCell;
    newCell->next = NULL;
    return l;
}

void print_list(Cell* l) {
    List tmp = l;
    while(tmp != NULL) {
        printf("%s %s %d\n",tmp->first_name,tmp->last_name,tmp->age);
        tmp = tmp->next;
    }
}