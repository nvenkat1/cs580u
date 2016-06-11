//Dynamic Memory: Memory Allocated on runtime.
#include<stdio.h>

int main(){
	//1
	void * ptr ;		//its pure memory
	printf("%d",ptr);	//prints zero its

	//2
	int x;
	void * ptr1 = &x;
	printf("%d",ptr);	//prints zero its

	//3
	int x1;
	void  * ptr =  &x;	//change void to int
	int y1 = x + 1;		//wont work! because it will change address with void pointer
	int  * y = ptr + 1;
	printf("%d", y);

	//4
	int x2;
	void * ptr2 = &x;
	void y2 = ptr2; 	// its working b/c auto casting is happening begind the scene.
	void *y = ptr + 1;	//this should give error as we dont know how much to add, as its void type
	printf("%d \t %d", ptr, y);	//even if we change it to int, it will still treating it as interger and printing value  of charcater.

	

	return 0;
}
