#include<stdio.h>

int main(){
	char name[51] ={0} , color[51] = {0}; //zero out the buffer,, null bytes
	int age = 0;	//notice above zeroing out till 51, for /0 character

	//try 1
	printf("\tEnter your \n\t1. Name\n\t2.Age\n\t");
	scanf("%50s %d", name, &age);	//doing in one line. add space inbetween %s and %d cool!!

	printf("%s, %d\n", name, age);

	//try2 : problem of flushing input!!
	printf("\nEnter name and age\n");
	scanf("%50s", name);

	//int age;
		//solution: getchar, getline (to consider spaces inbetween), gets (dont use, doesnt haev bounce check), getc)
		while(getchar()!= '\n');	// this is best to clear input buffer
	scanf("%d", &age);

	printf("%s, %d\n", name, age);
	//

	//printf("\tEnter your \n\t2. Age\n");
	//scanf("%d", &age);

	//try3
	printf("\n\tEnter Your fav Color\n");
	fscanf(stdin, "%50s", color);

	fprintf(stdout, "\tName=%s\n\tAge=%d\n\tcolor=%s\n",name, age, color);

return 0;
}
