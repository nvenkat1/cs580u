#include "data.h"
#include "bst.h"
#include<stdio.h>

int main(){
	Tree * tree = createTree();
	Data data[10];
	int array[] = {5, 7, 3, 8, 2, 6, 4, 9, 1};
	int i = 0;

#if PART1
	for( i = 0; i< (sizeof(array)/sizeof(int)); i++){
		data[i].num = array[i];
		insert(tree, data[i]);
	}

	for( i = 0; i< (sizeof(data)/sizeof(Data)); i++){
		printf("data[%d].num = %d\n", i, data[i].num);
	}
#endif
	return 0;
}
