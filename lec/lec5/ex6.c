#include<stdio.h>
#include<stdlib.h>

typedef struct s3{
	struct s  * ptr; // but here we will have to use struct keyword.
	 int i;
	char c;
}MyStruct;
//these are just numbers underneath ,{ 0= jan, 1=feb, 2=march}
enum  Months{ JANUARAY, FEBRUARY, MARCH }; //captital is optional.. 

//enum for union
enum UNION_TYPE(INT=1,CHAR=9);

union t1{		//it can contain only 1 data tppe  at given time
	int x;
	double d;
	char c;
}


struct  person{
        char *name;	//8 bytes	//doesnt allocate any space on heap.
	//try1 :
	//char buffer[225]; 	//alllocates spaces of 225 bytes
	//try 2: change size of buffer to 4
	//char buffer[4];		// 1 char = 1 byte * 4 =  4  bytes
	//try 3 : change size of buffer to 1
	//char buffer[1];		//should print 1 byte
	//try 4: add double;
	//double d;
};
struct t {
	int x;
}

//struct inside a stuct.
//cant do this.
struct  s {
	char * s;
	char buf[255];
	//struct s val;	NO!!	//compiler cant determine size of val
	sturct s *val;		//b/c size of pointer is fixed, hence compiler can allocated

	//in cimplicated program. how to know what type it is?
	//solution: tagging
	int TAG;
	enum UNION_TYPE TAG;
	union{
		int i;
		char c;
		} val;
	//use if enum
	enum Months month;
}
//typedef
typedef  struct {
	int i;
	char buf[255];
}MyStruct;

//solution use point

int main(){
	struct person p1 = malloc(sizeof(person));
	printf("%d\n", sizeof(p1));

	struct person s1 = malloc(sizeof(s));
	printf("%d\n", sizeof(p1));

	union t myunion;
	myunion.x = 5;
	myunion.d = 7.0;	//this will ovewrite above x.
	printf("%d\n", sizeof(union t));	//prints 8 byte , b/c max type is double which is 8 bytes.

	//union in struct, with TAG
     	struct s *p2 = malloc(sizeof(s));
	(*p2).val.i= 5;
	(*p2).tag = 2;	// this is how we can find in program which type is being used.
        printf("%d\n", sizeof(p1));

	//enums
	//we have limited fixed values
	// and we want to make types out of it/
	//E.g Jan, FEb, Mar..etc
	printf("%d\n", JANUARAY);

	//sp we can use enums for TAG
	different_int x;
	struct person s4 = malloc(sizeof(s));
        printf("%d\n", s->i);



	return 0;
}
