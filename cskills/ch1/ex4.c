#include<stdio.h>

int main(void){

	struct emp{
		//char name[20];
		int age[3];
		float sal[2];
	};

	struct emp1{
		//char name1[400];
		int age1;
		float sal1;
	};

	struct emp e;
	struct emp1 e1;
	//struct emp e = {};
	//struct emp e = {"Tiger"};
	//printf("\n age =%d sal=%f\n", e.age[0], e.sal[0]);
	printf("\n age =%d sal=%f\n", e1.age1, e1.sal1);

	printf("Size of struct1 %lu  struct2 %lu\n", sizeof(struct emp), sizeof(struct emp1));

return 0;
}

/*	this program will print age = 0 and sal=0.00000
	this is b/c when struct is defined partially,
	its other elements are initilized too.
	Which means, when I say e = { "Tiger" } this is like
	defining only 1 variable out of other 2

	so, even though, other elements will get initialized to zero.


	now, if I only declare e as struct emp e = { }
	even in this case, variable age and sal are initialzed/defiend to 0 and 0.00000


	now if I only declare struct emp e;
	then value of age and sal might not be initialzied to zero.
	more specifically,
	its int value wont be initialized to 0 -> age1 != 0 , it would be garbage value
	but its float value will be initizled to 0.00000

	as struct <name> is always consider as a whole type,
	to get sizeof() of this data type, b/c whole thing is considered as 
	a data type.
	so, it should be like this, sizeof(struct emp)
	instead of sizeof(emp);
	compiler will give error, that, Error: 'emp' is undefined 
*/

