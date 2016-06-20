//Dynamic Memory: Memory Allocated on runtime.
#include<stdio.h>

#define P1 1
#define P2 0
#define P3 0
#define P4 0


int main(){

#if P1
	//1
	int i = 5; char c = 'c'; float f = 1.23; double d = 1234.1234;
	int * intptr = &i; char * charptr = &c; float * floatptr = &f; double * doubleptr=&d;

	void * ptr ;					//its pure memory
	printf(" value of void  ptr = %d | Size of ptr = %d\n", ptr, sizeof(ptr));	//prints zero its
	printf(" *Iptr = %-10d Iptr =%-12p\n", *intptr, intptr);	//prints zero its
	printf(" *Cptr = %-10c Cptr =%-12p\n", *charptr, charptr);	//prints zero its
	printf(" *Fptr = %-10f Fptr =%-12p\n", *floatptr, floatptr);	//prints zero its
	printf(" *Dptr = %-10f Dptr =%-12p\n", *doubleptr, doubleptr);	//prints zero its
#endif

#if P2
	//2
	int x;
	void * ptr1 = &x;
	printf("%d", ptr1);	//prints zero
#endif

#if P3
	//3
	int x1;
	void  * ptr =  &x1;	//change void to int
	int y1 = x1 + 1;		//wont work! because it will change address with void pointer
	int  * y = ptr + 1;
	printf("%d", y);
#endif

#if P4
	//4
	int x2;
	void * ptr2 = &x;
	void y2 = ptr2; 	// its working b/c auto casting is happening begind the scene.
	void *y = ptr2 + 1;	//this should give error as we dont know how much to add, as its void type
	printf("%d \t %d", ptr2, y);	//even if we change it to int, it will still treating it as interger and printing value  of charcater.
#endif



	return 0;
}
