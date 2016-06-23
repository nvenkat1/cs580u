#include "data.h"
#include "bst.h"
#include<stdio.h>

int main(){
	int array[] = {5, 7, 3, 8, 2, 6, 4, 9, 1};
	Data data[10];
	int i = 0;

	for( i = 0; i< (sizeof(array)/sizeof(int)); i++){
		data[i].num = array[i];
	}
	for( i = 0; i< (sizeof(data)/sizeof(Data)); i++){
		printf("data[%d].num = %d\n", i, data[i].num);
	}

	return 0;
}
