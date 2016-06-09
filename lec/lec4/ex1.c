#include<stdio.h>

//#define DEBUG(x,t) printf("%t\n",x)		//it doenst support %t, %d... hence seperate it out!
//#define DEBUG(x,t) printf("%" + t + "\n",x)

#define THIRD 1/3
#define PI 3.14
#define TRUE 1
#define DEBUG 1			//Preprocessor replaces literal value, which are stored in registerd
				//Opposite to const which are stored in memeory.
#define SQARE (x) (x) * (x)
#define EQ ==


int main(){
	//1:
	 if(TRUE)	//if(DEBUG)
		printf("%f", PI);
	printf("%s", __FILE__);
	printf("%s", __DATE__);
	printf("%d", __LINE__);

	//2:
#ifdef DEBUG
	float f = SQARE(1+1);
#endif

	//3:
	f = 6 * THIRD;
return 0;
}
