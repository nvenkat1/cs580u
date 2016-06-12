#include<stdio.h>

int main(int argc, char *argv[]){
	int i = 0;
	printf("Value of argc: %d\n", argc);

	for( i = 1; i< argc; i++){
		printf("arg %d: %s\n", i , *(argv+i));
	}

	char * states[] = {"New York", "California", "Washington",
				"Texas"};
	/*Array of string: char * <name> = {"","",""};
	it is nothing but the pointers of strings.
	which means that,
	state[0] will have pointer stored
		= address of string 1st
	state[1] will have pointer stored
		= address of 2nd string element.
	like wise:
	*/
	int num_states = 4;

	for(i = 0; i <  num_states; i++)
		printf("State[%d] = %lu\t%p\n", i, *(states+i), *(states+i));


	for( i = 0; i<num_states; i++){
		printf("State %d: %s\n", i, *(states + i));
	}

	char * first[]=  { "one", "two", "three", "four", "five" };
	char * string1 = "1";
	char * string2 = "2";
	char * string3 = "3";
	char * string4 = "4";
	char * string5 = "5";
	char * second[] = { string1, string2, string3, string4, string5};

	for(i =0 ; i<5; i++){
		printf("First String = %s\t", *(first+i));
		printf("Second String = %s\n", *(second+i));
	}

	char  ***third = {first, second};
	int j = 0;
	for(i =0 ; i<2; i++){
		for(j =0 ;  j < 5 ; j++){
			printf("Third[%d] = \n", *(*(third+i) + j) );
		}
	}

	return 0;
}
