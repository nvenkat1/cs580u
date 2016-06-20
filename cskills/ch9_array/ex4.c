#include<stdio.h>

main()
{

	int a[] = {1,2,3,4,5};
	int *b = {1,2,3,4,5};
	printf("\n%d %d", sizeof(a), sizeof(b));
	printf("\n%d %d", sizeof(*a), sizeof(*b));

}
