#include "data.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

Vector * createVector(){
	Vector *v = malloc(sizeof(Vector));		//TODO: Dealloacte this
	(*v).data = NULL;
	(*v).current_size = 0;
	(*v).capacity = 0;
	return v;
}
void vectorInsert(Vector *v, int index, Data data){

	if(index >= (*v).capacity){
		if((*v).capacity == 0){
			(*v).capacity = 1;
		}
		(*v).capacity = ((*v).capacity *2) + 1;
		Data *newData = malloc(sizeof(Data) * (*v).capacity);
		//memcpy( newData, '\0', sizeof(Data) * (*v).current_size);
		//Step 1 : Copy all element from old data location to new data location.
		memcpy( newData, (*v).data, sizeof(Data) * (*v).current_size);
		//Step 2 : Free old data pointer
		//for first time, (*v).data would be null, but still we can call free on NULL. Its a nop
		free((*v).data);
		//Step 3 : Assign Newdata with new size's memory loation to old data pointer of struct vector
		(*v).data =  newData;
	}else if( index < (*v).current_size){
		(*v).current_size = index + 1;
	}else{
		//(*v).current_size++;
	}
	v->data[index] = data;
	(*v).current_size = index+  1;


}

Data* vectorRead(Vector *v, int index){
	if(index >= (*v).current_size){
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
