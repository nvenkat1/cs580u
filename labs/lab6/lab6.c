#include "data.h"
#include "list.h"

#include<stdio.h>
#include<time.h>

int main(){
	srand(time(NULL));
	Data dataArray1[10];
	int i = 0, result=-1;
	List  * list1 = createList();

	printf("Indexing Starts from 0\n");
	printf("Generating 0-10 array of Data struct \nand Adding Randomly at index 0-15\n");
	for (i = 0 ; i < 10 ; i++){
		dataArray1[i].num = i+1;
		int index = rand() % 15 + 1;
		printf("\tAdding %d at %d\n", dataArray1[i].num, index-1);
		insertData(list1, index, dataArray1[i]);
		printList(list1);
		//printListReverse(list1);
	}

	printf("\nInserting random value = %d at index 20\n", dataArray1[9].num);
	insertData(list1, 20, dataArray1[9]);
	printList(list1);

	printf("\nDeleting List at Random Index\n");
	for( i = 0 ; i < totalCount(list1); i++){
		int index = rand() % 25 + 1;
		printf("\tDeleting at index = %d\n", index-1);
		result = removeData(list1, index);
		printList(list1);
	}


#if DELETE_1
	printf("\tDelete Test\n");

	printf("\tDeleting any middle element\n");
	printList(list1);
	//result = removeData(list1,2);	//second  total 11, -1 =10
	//result = removeData(list1,5);	//middle  total 10, -1 = 9
	//result = removeData(list1,9);	//last    toatl 9,  -1 = 8
	result = removeData(list1,12);	//out of bound
	result = removeData(list1,50);	//out of bound
	result = removeData(list1,100);	//out of bound
	result = removeData(list1,10000);	//out of bound
	if(result == 1){
		printf("\tIndex Out of Bound\n");
	}
	printf("\tAfter Deleting at given index 2\n");
	printList(list1);
	printf("\t Deleting middle element test passed\n");
	printf("\tTotal Number of elements in List %d\n", totalCount(list1));

#endif

#if DELETE_2
	printf("\tIf only 1 element present\n");
	list1->head= NULL;
	insertData(list1, 20, dataArray1[9]);
	printf("\tBefore Deleting only element\n");
	printList(list1);
	result = -1;
	result = removeData(list1, 5);
	if(result == 1){
		printf("\tIndex Out of Bound\n");
	}
	printf("\tAfter Deleting only element\n");
	printList(list1);
	printf("\t Deleting only element test passed\n");

#endif

	//printf("After Deleting 1st index value\n");
	//printList(list1);

	list1 = freeList(list1);

	return 0;
}
