#include <stdio.h>
#include <stdlib.h>

int * create_array(int size);
void fill_array(int * array, int size);
void print_array(int * array, int size);

int main(int argc, char* argv[]){
	if(argc<2) {
		printf("Veuillez rentrez un argument lors du lancement du programme\n");
		return 1;
	}

	int size = 0;
	size = atoi(argv[1]);

	int * array;
	array = create_array(size);

	fill_array(array, size);

	print_array(array, size);

	free(array);
	return 0;
}

int* create_array(int size) {
	int* array;
	array = (int*)malloc(size*sizeof(int));
	if(array == NULL) {
		printf("Problème d'allocution de mémoire\n");
		exit(1);
	}
	return array;
}

void fill_array(int * array, int size) {
	int i;
	for(i=0; i < size; i++) {
		array[i] = i+1;
	} 
}

void print_array(int * array, int size) {
	int i;
	for(i=0; i < size; i++) {
		printf("%d ",array[i]);
	}
}