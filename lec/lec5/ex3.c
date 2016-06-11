//CW28 : allocating space

#include<stdio.h>
#include<stdlib.h>

int main(){
	int * x = malloc(sizeof(int));	//will give 4 bytes of  memory in heap
	int j = 0;
	for( j = 0; j<5; j++){
		printf("%d \n", x+j);
	}
	memset(x,1,sizeof(int)*5);
	for( j = 0; j<5; j++){
		printf("Address : %d \t Values : %d \n", x+j, *(x+(j)));
	}

return 0;
}
