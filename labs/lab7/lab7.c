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
	printf("\n\tSearching Data value 1 in Tree\n");
	Data *searchResult = findNode(tree, data[8]);
	if(searchResult!=NULL)
		printf("\tGiven Data value %d, Found in Tree with Node value: %d\n", data[8], searchResult->num);

	//int input= -1;
	Data input;
	input.num=-1;
	do{
		printf("\n\tEnter value to search \n\t");
		scanf("%d", &(input.num));

		if(input.num!= 0 && input.num!=-1 ){
			printf("\n\tSearching Data value %d in Tree\n", input.num);
			searchResult = findNode(tree, input);
			if(searchResult!=NULL)
				printf("\tSearch succeeded!\n");
		}

		if(input.num == -1){
			printf("\tInvalid input\n");
		}
	}while(input.num!=0 && input.num!= -1);	
	//-1 is initioal value, this check is added if user enters character, 
	//if he entered character, it will only catch -1 in %d of scanf and 
	// we can exit from there from infinite loop
#endif
	return 0;
}
