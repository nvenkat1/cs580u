#include "vector.h"
#include<stdlib.h>

Data* initVector(Data *d, int current_size, int capacity){
        Data *d = malloc(sizeof(Data));
	d= NULL;
	d->current_size = 0;
	d->capacity = 0;
        return d;

}
void  deleteVecotr(Data *d){
        //free(d);
        free(d);
}

