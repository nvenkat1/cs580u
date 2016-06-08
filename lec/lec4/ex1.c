#include<stdio.h>

//#define DEBUG(x,t) printf("%t\n",x)		//it doenst support %t, %d... hence seperate it out!

#define DEBUG(x,t) printf("%" + t + "\n",x)
#define THIRD 1/3
#define PI 3.14
#define TRUE 1
#define DEBUG 1			//Preprocessor replaces literal value, which are stored in registerd
				//Opposite to const which are stored in memeory.
#define EQ ==


int main(){
	 if(TRUE)	//if(DEBUG)
		printf("%f", PI);
	printf("%s", __FILE__);
	printf("%s", __DATE__);
	printf("%d", __LINE__);



	float  f = 6 * THIRD;
return 0;
}
