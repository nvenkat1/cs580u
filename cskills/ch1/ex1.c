#include<stdio.h>
int main(){
	char *s1, *s2;
	printf("size:%lu %lu\n",sizeof(s1), sizeof(s2));

	void *v1;
	printf("size:%lu\n",sizeof(v1));

	int *i1;
	printf("size:%lu \n",sizeof(i1));

	char c1[]= "Hello";
	char *c2 = "Hello";
	printf("c1:%p c2:%p\n",c1, c2);

/*Notes:
	everypointer has fixed size value.
	if you do sizeof(p); where p i pointer to any data type
	let it be: int *p, char *p, double *p, or even int *p = str
	where int str[100]; (means pointer to array)

	point is, pointers are storing address, which means its value 
	should range from memory address 0 to max possible

	so, actually size of pointer depends upon the machine architecture
	for 32 bit machine, memory address possible are, from 0 to 2^32-1
	for 64 bit machine, memory address possible are, from 0 to 2^64-1

	so for 32 bit machine, max bits for any address would be = 32 bits address
	so for 64 bit machine, max bits for any address would be = 64 bits address

	32 bit address = 1bytes 1bytes 1bytes 1bytes = 4 bytes in total
	64 bit address = 1bytes 1bytes 1bytes 1bytes 1byte 1byte 1byte 1byte = 8 bytes in total

	and sizeof returns size in bytes.
	so for,
	32 bit machine: size of any pointer would be = 4 bytes
	64 bit machine: size of any pointer would be = 8 bytes

	which means, they can store 4bytes and 8bytes max for 32 and 64 bit machines.
*/
return 0;
}
