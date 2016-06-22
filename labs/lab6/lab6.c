#include "data.h"
#include "list.h"

#include<stdio.h>
#include<time.h>

int main(){
	srand(time(NULL));
	Data dataArray1[10];
	int i = 0, result=-1;
	List  * list1 = createList();
#if PART_A
#if INSERT
	printf("\n####PARTA####\nIndexing Starts from 0\n");
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

	int num;
        printf("\n\tEnter number to search (0-10)\n\t>>");
        scanf("\t%d",&num);

        int forwardIndex = searchForward(list1, num);
        int backwardIndex = searchBackward(list1, num);

        if(forwardIndex != -1 || backwardIndex != -1){
                printf("\tForward Index = %d\n\tBackward Index = %d\n", forwardIndex, backwardIndex);
        }else{
                printf("\t Array index out of bound\n");
                printf("\tForward Index = %d\n\tBackward Index = %d\n", 0, 0);
        }
#endif

#if READ
	printf("\nReading at random index\n");
	int index = rand() % 10 + 1;
	Data * data = readData(list1, index);
	printf("\tData at random index %d  = %d\n", index-1, (*data).num);

#endif

#if DELETE
	if(Empty(list1)==0){
		printf("\tList is empty\n\n");
	}
#endif

#endif 	//PARTA


#if PART_B
        /*printf("\n\n####PARTB####\nGenerating 0-10 array of Data struct \nand Adding Randomly at index 0-15\n");
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

	int num;
	printf("\n\tEnter number to search (0-10)\n\t>>");
	scanf("\t%d",&num);

	int forwardIndex = searchForward(list1, num);
	int backwardIndex = searchBackward(list1, num);

	if(forwardIndex != -1 || backwardIndex != -1){
		printf("\tForward Index = %d\n\tBackward Index = %d\n", forwardIndex, backwardIndex);
	}else{
		printf("\t Array index out of bound\n");
		printf("\tForward Index = %d\n\tBackward Index = %d\n", 0, 0);
	}
	*/
#endif //PARTB

	list1 = freeList(list1);


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

	return 0;
}
