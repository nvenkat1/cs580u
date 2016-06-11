#include<stdio.h>
#include<stdlib.h>

int main(){
	int * ptr;
	//if no mememory reutnr null
	ptr = malloc(sizeof(int));

	//if(ptr = malloc(sizeof(int)) == NULL){
	//	exit(-1);
	//}
	*ptr = 5;
	//deallocating, easy
	free(ptr);		//os sometimes can zero it out.
	int x = *ptr;
	//to not to get seg fault;
	ptr = NULL;		// null it out

	free(ptr);		// we can call free on null pointer.
	printf("%d\n", x); 	// it will still give some value like 0..
	printf("%d\n", *ptr); 	// it will still give some value like 0..



	return 0;
}
