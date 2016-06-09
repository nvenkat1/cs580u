#include<stdio.h>

void foo(int * arr, int index){
	*(arr + index) = 5;
}
int main(){

	int arrayInt[5]={5,5,5,5,5};
	int testArray[5];
	//int valueOutofBoundTest = arrayInt[5];
	//arrayInt[5] = 6;
	//printf("%d",valueOutofBoundTest);
	int i;
	for(i=0;i<5;i++)
		foo(testArray,i);

return 0;
}
