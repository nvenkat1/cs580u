#include<stdio.h>

int main(){
	extern int i;
	//i = 20;
	printf("%lu\n", sizeof(i));
	printf("%d\n", i);
return 0;
}
int i =20;



/*	you can define and declare variable out side of main
	so it can be before main body or after main body.
	it still will display value of i = 20.

	extern int i; 	is just a declaration, not defination.
	this means that it is definded somewhere else.
	not if I just that i as, i=20 in next line,
	which will give error: cant find reference to varible i.
	which means that variable i is not yet declared for this program.

	declartion vs defination
	declaration : only data type of variable is determinded.
		and not storage is done yet.

	defination: here variable is given some initial value,
		hence storage is allocated at this time.

	If defination of any variable is there, bfore using that variable,
	then we dont need to specify extern keyword to tell compiler that its
	defination is somewhere else. As complier has already found its defination.
*/
