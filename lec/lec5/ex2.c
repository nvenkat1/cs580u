#include<stdio.h>
#include<stdlib.h>

int getSize(void *ptr){
	return sizeof(*ptr);
}
int main(){
	//1
	int x = 10;
	int sizeOfx = getSize(x);
	printf("Size of x = %d", sizeOfx);

	//2
	int arrayInt[10];
	int *ptrToArray = arrayInt;
	int sizeofArray = getSize(ptrToArray);
	printf("Size of array = %d", sizeofArray);

	//3
	int l1[5];
	printf("%d\n", getSize(l1);

	//malloc return void*, complier auto cast it to int.in this case.
	int *x = malloc(4);	//malloc return the address, void pointer
	//int x = (int *) malloc(4);	//dont use (int *) b/c user can have their own malloc written, and they can return differnt return part. other than  *void
	printf("%d\n", getSize(x));	//while printing %d autocase is happeningi

	int *y = malloc(4); 	// as we want 4 bytes for int variable 
				// but differnt machine can have different int value like 2 butes and not 4 bytes
	int *y1 = malloc(sizeof(int)) // best practice.

	char * aa = malloc(sizeof(int)*2); 	//for 8 bytes , 4 *2 =8 byes or 8 * 2= 16 bytes
	//we can use, char * aa= malloc(1); 	//bcoz size of byte and char is same! nO problem.
	strcpy(aa, "hhelllooo");	//why it doenst give error, bcz malloc doenst care about where you are using that given memeory


	char * aaa = malloc(sizeof(char)*2);
	printf(" %d %d\m", aaa[0], aaa[1]);	// malloc doenst zero that out!
	//Solution to zeroing it out : use calloc
	//allocate + zeroing out, take 2 parameter
	char *ab =  calloc(2, sizeof(char));	//no of element and size of elemet

	//no bounce check by malloc : it will overwritten by  it.
	char *abc = malloc(sizeof(char)*2);
	printf(" %d\n", abc[2]);		//doenst give error, malloc doesnt care for what ur using that memory


	char *ptr3 = malloc(sizeof(int));	//doenst give error,
	char *ptr4 = malloc(sizeof(int));	//doenst give error,
	*ptr3 = 8;				//allocation and deallocation handled automatically.
	*(ptr3 + 1) = 5;
	printf("%d  %d \n", ptr3 ,ptr4, ptr3[1]);	//in case if that was allocated squencially, which is not alwatys the case, we can overwrite it 

	//alternate way to zeroing out memory using memset
	char *ptr5 = malloc(sizeof(int));	//doenst give error,
	memset(ptr5, 0, sizeof(int));/*size_t type ,size of bytes*/
	printf("%d\n", ptr);

return 0;
}
