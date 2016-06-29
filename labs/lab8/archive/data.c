#include "data.h"
#include<stdlib.h>

Data* initData(City *city){
	Data *data = malloc(sizeof(Data));
	data->city = city;
	return data;
}

void* deleteData(Data *data){
	free(data);
	data = NULL;
	return NULL;
}
