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
void vectorInsert(Vector *array, int index, Data value){

#if DEBUG_1
	printf("currentsize = %d capacity = %d (*v).data = %d *(*v).data = %d\n", (*array).current_size, (*array).capacity, (*array).data, *(*array).data );
#endif
	if(index >= (*array).capacity){
		(*array).capacity *= 2 + 1;
#if DEBUG_1
        printf("currentsize = %d capacity = %d (*v).data = %d *(*v).data = %d\n", (*array).current_size, (*array).capacity, (*array).data, *(*array).data );
#endif
		Data *newData = malloc(sizeof(Data) * (*array).capacity);
#if DEBUG_1
        printf("currentsize = %d capacity = %d (*v).data = %d *(*v).data = %d\n", (*array).current_size, (*array).capacity, (*array).data, *(*array).data );
#endif
		//memcpy( newData, '\0', sizeof(Data) * (*v).current_size);
		//Step 1 : Copy all element from old data location to new data location.
		memcpy( newData, (*array).data, sizeof(Data) * (*array).current_size);
#if DEBUG_1
        printf("(*newData).data = %d\n", (*newData).num );
#endif
		//Step 2 : Free old data
		//for first time, (*v).data would be null, but still we can call free on NULL. Its a nop
		free((*array).data);
#if DEBUG_1
        printf("(*v).data = %d *(*v).data = %d\n", (*array).data, *(*array).data );
#endif
		//Step 3 : Assign Newdata with new size's memory loation to old data pointer of struct vector
		(*array).data =  newData;
#if DEBUG_1
        printf("currentsize = %d capacity = %d (*v).data = %d *(*v).data = %d\n", (*array).current_size, (*array).capacity, (*array).data, *(*array).data );
#endif
		(*array).current_size += 1;
#if DEBUG_1
        printf("currentsize = %d capacity = %d (*v).data = %d *(*v).data = %d\n", (*array).current_size, (*array).capacity, (*array).data, *(*array).data );
#endif
	}
	*((*array).data).num = value.num;
#if DEBUG_1
        printf("currentsize = %d capacity = %d (*v).data = %d *(*v).data = %d\n", (*array).current_size, (*array).capacity, (*array).data, *(*array).data );
#endif

}

