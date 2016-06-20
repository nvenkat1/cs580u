#include<stdio.h>
#include<stdlib.h>

int main(){
        int * ptr = (int *) malloc(sizeof(int));
        printf("%p\n", ptr);
        printf("%d\n", *ptr);

	int str[] = "Name";

        *ptr = 8;
        printf("%d\n", *ptr);

	/* There is difference between 
	* ptr = 8; and
	* ptr = str; but not *ptr = str[0];
	b/c 8 is a literal.

	ptr will have an address.
	so we are trying to store 8 at this address by, saying
	value at address ptr = 8
	*ptr = 8

	but in case of array, we have str[]. 
	this str[] is nothing but, *str = pointer to str[0],
	means, first element of continuous locations.

	so *str[0] would be some value of an array
	but str has address of that array, which has continious location
	starting from 0.

	hence, we should store that address to same address variable.
	special case,
	for array when we declare pointer,
	this is just for an array, when we declare and say
	int *ptr = str;
	this left side side, even if it looks like storing at that address,
	but its taking address for that array.

	so, int *ptr will not take value at that memory location but 
	is ready to access address of that array.

	so, we write, int *ptr = str;
	store address of str to, which is address to be stored at ptr */

        *(ptr + 1) = 5;
        printf("%d\n", *ptr);
        printf("%d\n", *(ptr+1));
        printf("%d\n", *(ptr+2));
        //printf("%lu\n", sizeof(ptr));
        //printf("%lu\n", sizeof(*ptr));
        //printf("size of *ptr= %d", sizeof(ptr));
        //printf("size of *ptr= %d", sizeof(ptr));
        return 0;

}
