#include<stdio.h>

fun();			//fixed it!
int main(void){
	int (*p)() = fun;
	(*p)();
	return 0;
}
fun(){
	printf("Loud and clear\n");
}

/*	to point to fun, we need to declare it with ()()
	int (*p)() = fun.
	but in this case, if I dont add prototype at the start, and then
	excute, pointer will dont know which address to store,
	as function is not even declared.
	error : 'fun' undeclared
*/


