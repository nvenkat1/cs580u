#include "data.h"
#include<stdlib.h>

Data* initData(char *old, int num){
	Data *d = malloc(sizeof(Data));
	d->str = malloc(strlen(old+1));
	strcpy(d->str, old);
	d->num = num;
	return d;

}
void * deleteData(Data *d){
	free(d->str);
	free(d);
	return NULL;
}
