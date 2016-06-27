#include "data.h"
#include<stdlib.h>

Data* initData(int num){
	Data *data = malloc(sizeof(Data));
	data->num = num;
	return data;
}

void* deleteData(Data *data){
	free(data);
	data = NULL;
	return NULL;
}
