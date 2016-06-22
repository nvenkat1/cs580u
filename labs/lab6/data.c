#include "data.h"
#include<stdlib.h>

Data* initData(int num){
	Data *d = malloc(sizeof(Data));
	d->num = num;
	return d;
}

void  deleteData(Data *d){
	free(d);
	//return NULL;
}
