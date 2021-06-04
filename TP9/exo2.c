#include <stdio.h>
#include <stdlib.h>

char** create_array(int sizeUn, int sizeDeux);
void fill_array(char ** array, int sizeUn, int sizeDeux);
void print_array(char ** array, int sizeUn, int sizeDeux);
void free_array(char ** array, int sizeDeux);

int main() {
	int sizeUn = 0;
	int sizeDeux = 0;

	printf("Donnez deux dimensions entières : ");
	scanf("%d %d",&sizeUn,&sizeDeux);

	char ** array;
	array = create_array(sizeUn, sizeDeux);

	fill_array(array, sizeUn, sizeDeux);

	print_array(array, sizeUn, sizeDeux);

	free_array(array, sizeDeux);

	return 0;
}

char** create_array(int sizeUn, int sizeDeux) {
	int i;
	char** array;
	if ((array=(char**)malloc(sizeUn*sizeof(char*)))==NULL) {
		printf("Erreur d'allocation");
		exit(1);
	}
	for(i=0; i<sizeUn; i++) {
		if ((array[i]=(char*)malloc(sizeDeux*sizeof(char)))==NULL) {
			printf("Erreur d'allocation");
			exit(1);
		}
	}
	return array;
}

void fill_array(char ** array, int sizeUn, int sizeDeux) {
	int i, j;
	for(i=0; i<sizeUn; i++) {
		for(j=0; j<sizeDeux; j++) {
			array[i][j]='a'+(i+j)%26;
		}
	}
}

void print_array(char ** array, int sizeUn, int sizeDeux) {
	int i,j;
	for(i=0; i<sizeUn; i++) {
		for(j=0; j<sizeDeux; j++) {
			printf("%c ",array[i][j]);
		}
		putchar('\n');
	}
}

void free_array(char ** array, int sizeDeux) {
	int i;
	for(i=0; i<sizeDeux; i++) {
		free(array[i]);
	}
	free(array);
}