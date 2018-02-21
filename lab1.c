#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include "omp.h"

int arraySize( int dim[]){ //calculate array size by computing product of dimensions, uses zero-terminated array
	int count = dim[0];
	int i = 1;
	while(dim[i] != 0){
		count = count * dim[i];
		i++;
	}
	return count;
}

void initialize( int* array, int dim[]){ //intitializes all elements in an n-dimensional array to zero
	int size = arraySize(dim);
	for(int i = 0; i<size;i++){
		array[i] = 0;
	}
}

int* makeDynamicIntArray(int size){ //make one dimensional integer array
	int* array = malloc(size * sizeof(int));
	/*if(array = NULL){
		fprintf(stderr, "malloc failed\n");
	}*/
	return array;
}

int* makeMultiDimensionalIntArray(int dim[]){
	int size = arraySize(dim);
	return makeDynamicIntArray(size);
}

void printArray(int* array, int size){
	for(int i = 0;i<size;i++){
		printf("%3d", array[i]);
	}
}

void tenPercentOnes(int* array, int dim[]){ //sets 10 percent of the array elements to ones
	clock_t t;
	
	srand((unsigned) time(&t));
	int size = arraySize(dim);
	int tenPercent = size * 0.1; //10 percent of the array
	
	for(int i = 0; i < tenPercent ; i++){
		int index = rand()% size;
		array[index] = 1;
	}
}

void getIndexAndValue(int* array, int dim[]){

	//int fivePercent = size * 0.05; // 5 percent of the array
	
	
	
}



int numDimensions(int dim[]){
	int counter = 0;
	while(dim[counter] != 0){
		counter = counter + 1;
	}
	return counter;
}


int* makeRandIndex(int dim[]){ //return a randon co-ordinate in the bounds of 'dim'
	clock_t t;
	srand((unsigned) time(&t));
	int size = numDimensions(dim) - 1;
	int* temp = makeDynamicIntArray(size);

	for(int i = 0;i < size - 1;i++){
		temp[i] = rand()%dim[i];
	}
	
	return temp;
}

int main(){
	int dim[] = {3,6,0};
	
	
	//int* array = makeMultiDimensionalIntArray(dim);
	//initialize(array,dim);
	//tenPercentOnes(array,dim);
	//printf("%d", array[0]);
	int* indices = makeRandIndex(dim);
	//printArray(array,arraySize(dim));
	printArray(indices,numDimensions(dim));
	
	//free(array);
	
	return(0);
}
