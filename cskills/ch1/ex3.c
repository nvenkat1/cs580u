#include<stdio.h>

int main(void){

	int a[5] = {2,3};
	printf("\n %d %d %d\n", a[2], a[3], a[4]);
	printf("\n %d %d %d\n", *(a+2), *(a+3), *(a+4));

	int b[5];
	printf("\n %d %d %d\n", b[2], b[3], b[4]);
	printf("\n %d %d %d\n", *(b+2), *(b+3), *(b+4));

	int c[5];
	printf("\n %d %d %d\n", c[5], c[6], c[7]);
	printf("\n %d %d %d\n", *(c+5), *(c+6), *(c+100));



return 0;
}
/* 	when any array is initialized
	and only some of those total initialized size variable are assigned some values
	then all remaining values are initialized to zero by complier.

	But when, none of the values are initialized then
	if we try to print those values we will see garbage values.

	if we try to print values from memory location which do not beling to
	declared variable, then it will give garbage value again
	And if sometime location we are accessing is not in same segment,
	we could get segmentation fault error.

*/

