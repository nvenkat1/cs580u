//Input
#include<stdio.h>

int main(){
	printf("Enter a  Number:");
	int *x = 0;
	int z = 2 + 3;
//1
	fprintf(stdout, "%d\n", x);	// run without \n and wth \n : line break clear out the buffer
	fprintf(stdout, "%d\n", *x); 	//deferencing causes segmentation fault
	//printf("%d\n",y);
//2
//stdout is buffer whereas stderr is not
	fprintf(stderr, "%d\n", x);
	fprintf(stderr, "%d\n", *x);
//3
	printf("%d\n", x);
	fflush();		//fflush only works for outout but not for input.
	printf("%d\n", *x);	//it will give segmentation fault

//Scanf
	int y =0;
	scanf("%d", &y);

	char z[6];
	//scanf("%s", z);	//it doenst check for bounce check, it will write whole incoming string
	scanf("%5s", z);	//hence use bound like %5s , this is call limiting buffer. For security
	//scanf("%255s", z);	//

	prinf("%s\n", z);


return 0;
}
