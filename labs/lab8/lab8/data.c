#include "data.h"
#include "city.h"
#include<stdlib.h>

Data* initData(City *city){
	Data *data = malloc(sizeof(Data));
	data->city = createCity(city->name, city->x, city->y);
	return data;
}

void* deleteData(Data *data){
	data->city = deleteCity(data->city);
	free(data);
	data = NULL;
	return NULL;
}

