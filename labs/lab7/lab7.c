#include "data.h"
#include "bst.h"
#include<stdio.h>

int main(){
	Tree * tree = createTree();
	Data data[10];
	int array[] = {5, 7, 3, 8, 2, 6, 4, 9, 1};
	int i = 0;

#if PART1
	printf("\tInserting given Values in Tree: {5, 7, 3, 8, 2, 6, 4, 9, 1} \n");
	for( i = 0; i< (sizeof(array)/sizeof(int)); i++){
		data[i].num = array[i];
		insert(tree, data[i]);
	}
	printf("\tInserting Completed!\n");

#if DEBUG1
	for( i = 0; i< (sizeof(data)/sizeof(Data)); i++){
		printf("data[%d].num = %d\n", i, data[i].num);
	}
#endif
	//Duplicate Value insert Test
	printf("\tInserting Duplicate value in Tree\n");
	insert(tree,data[0]);
#endif


#if PART2
	printf("\n\tSearching Data value 9 in Tree\n");
	Data *search = findNode(tree, data[7]);
	if(search!=NULL)
		printf("\tGiven Data value %d, Found in Tree with Node value: %d\n", data[7], search->num);
	printf("\n\tSearching Data value 1 in Tree\n");
	search = findNode(tree, data[8]);
	if(search!=NULL)
		printf("\tGiven Data value %d, Found in Tree with Node value: %d\n", data[8], search->num);
#endif
	return 0;
}
