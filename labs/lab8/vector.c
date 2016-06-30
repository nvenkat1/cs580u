//#include "data.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

Vector * createVector(){
	Vector *v = malloc(sizeof(Vector));		//TODO: Dealloacte this
	(*v).data = NULL;
	(*v).current_size = 0;
	(*v).capacity = 0;
	return v;
}
Data* vectorRead(Vector *v, int index){
	if(index < 0) 
		fprintf(stderr, "Invalid Index\n");
	if(index > (*v).current_size){	//remove >=
		return NULL;
	}
	return (*v).data;
}

void vectorRemove(Vector *v, int index){
	if(index >= (*v).current_size){
		return;
	}else if(index == (*v).current_size){

	}

	int i = 0;
	for ( i = index ; i< (*v).current_size-1;  i++){
		v->data[i] = v->data[i+1];
#if DEBUG_1
		printf("\n%d\n", v->data[i]);
#endif
	}
#if DEBUG_1
	printf(" current size\n %d\n", (*v).current_size);
#endif
	((*v).current_size)--;
#if DEBUG_1
	printf(" current size\n %d\n", (*v).current_size);
#endif
}

void * deleteVector(Vector *v){
	//free((*v).data);
	v->data = deleteData(v->data);
	free(v);
	return NULL;
}
void vectorInsert3(Vector *v, int index, Data dataIn){
	if(index >= (*v).capacity){
		if((*v).capacity == 0){
			(*v).capacity = 1;
		}
		while(index >= (*v).capacity){
			v->capacity = (v->capacity * 3)/2 + 1;
		}
		Data *newData = malloc(sizeof(Data) * (*v).capacity);
		memcpy( newData, (*v).data, sizeof(Data) * (*v).current_size); //changed from cusize to cpacityr
		free((*v).data);
		(*v).data =  newData;
	}else if( index < (*v).current_size){

	}else{
	}
	//v->data[index] = dataIn;
	(*v).data[index] = *(initData(dataIn.city));
	(*v).current_size = index+  1;
}

void printVector(Vector *v){
	int i = 0;
	for( i =0 ; i< (v->current_size) ; i++)
		printf("\tName:%s, X=%d, Y=%d\n", v->data[i].city->name, v->data[i].city->x, v->data[i].city->y);
}
