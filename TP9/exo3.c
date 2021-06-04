#include <stdio.h>
#include <stdlib.h>

char** create_array_argc(int size);
char* create_array_smallest_possible(int size);
void display_tab(char** tab, int size);
void free_tab(char** tab, int size);

int main(int argc, char* argv[]){
    int i, j, lenght;

    char ** tab = NULL;
    tab = create_array_argc(argc);

    for(i = 0; i<argc; i++) {
        lenght = 0;
        for(j=0; argv[i][j]!='\0'; j++) {
            lenght++;
        }
        printf("%d\n",i);
        tab[i] = create_array_smallest_possible(lenght+1);
        for(j=0; j<lenght; j++) {
            tab[i][j] = argv[i][j];
        }
    }

    display_tab(tab, argc);

    free_tab(tab, argc);

    return 0;
}

char** create_array_argc(int size) {
	char** array;
	if ((array=(char**)malloc(size*sizeof(char*)))==NULL) {
		printf("Erreur d'allocation");
		exit(1);
	}
	return array;
}

char* create_array_smallest_possible(int size) {
    char* array;
	if ((array=(char*)malloc(size*sizeof(char)))==NULL) {
		printf("Erreur d'allocation");
		exit(1);
	}
    return array;
}

void display_tab(char** tab, int size) {
    int i;
    for(i = 0; i<size; i++) {
        printf("%s\n", tab[i]);
    }
}

void free_tab(char** tab, int size) {
    int i;
    for(i = 0; i<size; i++) {
        free(tab[i]);
    }
    free(tab);
}