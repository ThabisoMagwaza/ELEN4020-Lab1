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


int numDimensions(int dim[]){
	int counter = 0;
	while(dim[counter] != 0){
		counter = counter + 1;
	}
	return counter;
}



int* makeRandIndex(int dim[]){ //return a randon co-ordinate in the bounds of 'dim'
	//clock_t t;
	//srand((unsigned) time(&t));
	int size = numDimensions(dim);
	int* temp = makeDynamicIntArray(size);

	for(int i = 0;i < size;i++){
		temp[i] = rand()%dim[i];
	}
	
	return temp;
}



int coordinateToIndex(int* coordinate,int dim[]){
	int index = 0;
	int dimensions = numDimensions(dim);
	for(int i = 0;i < dimensions;i++){
		int sum = coordinate[i];
		for(int j = i+1;j<dimensions;j++){
			sum = sum * dim[j];
		}
		index = index + sum;
	}
	
	return index;
}

void getIndexAndValue(int* array, int dim[]){ //picks and random co-ordinate in the array and prints out the value contained in it
	
	int size = arraySize(dim);
	int fivepercent = size * 0.05; //five percent of the array
	
	for(int i = 0;i < fivepercent ;i++){
		int* coordinate = makeRandIndex(dim);
		printf("Co-ordinate\n");
		printArray(coordinate,numDimensions(dim));
		printf("\n value\n");
		int index =  coordinateToIndex(coordinate,dim);
		printf("%d",array[index]);
		printf("\n\n");
		free(coordinate);
	
	}
	
	
}

int main(){
	clock_t t;
	srand((unsigned) time(&t));
	
	printf("----------- Array 1 --------- \n\n");
	int dim[] = {100,100,0};
	int* array = makeMultiDimensionalIntArray(dim);
	initialize(array,dim); //method 1
	tenPercentOnes(array,dim); // method2
	getIndexAndValue(array,dim); //method 3
	
	printf("----------- Array 2 --------- \n\n");
	int dim2[] = {100,100,100,0};
	int* array2 = makeMultiDimensionalIntArray(dim2);
	initialize(array2,dim2); //method 1
	tenPercentOnes(array2,dim2); // method2
	getIndexAndValue(array2,dim2); //method 3
	
	printf("----------- Array 3 --------- \n\n");
	int dim3[] = {50,50,50,0};
	int* array3 = makeMultiDimensionalIntArray(dim3);
	initialize(array3,dim3); //method 1
	tenPercentOnes(array3,dim3); // method2
	getIndexAndValue(array3,dim3); //method 3
	
	printf("----------- Array 4 --------- \n\n");
	int dim4[] = {20,20,20,20,0};
	int* array4 = makeMultiDimensionalIntArray(dim4);
	initialize(array4,dim4); //method 1
	tenPercentOnes(array4,dim4); // method2
	getIndexAndValue(array4,dim4); //method 3
	
	free(array);
	free(array2);
	free(array3);
	free(array4);
	return(0);
}
