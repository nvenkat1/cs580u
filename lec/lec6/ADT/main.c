#include "vector.h"
//#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	Vector *v = initVector();
        //printf("Data: [current_size: %d, capacity = %d]\n", d->current_size, d->capacity);
        //deleteData(d);                //combine next step
        //d = NULL;               //remember this.
        //this will give int value as garbage value
        //and stiing as null. it wont initialized it for you.
	v = deleteVector(v);
	free(NULL);
        return 0;
}

