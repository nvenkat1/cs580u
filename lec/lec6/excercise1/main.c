#include "data.h"
//#include<stdlib.h>
#include<stdio.h>

int main(){
	//Data *d = malloc(sizeof(Data));
	Data *d = initData("data",1);
	printf("Data: [string: %s, int = %d]\n", d->str, d->num);
	d = deleteData(d);		//combine next step
	//deleteData(d);		//combine next step
	d = NULL;		//remember this.
	//this will give int value as garbage value
	//and stiing as null. it wont initialized it for you.
	return 0;
}
