#include "person.h"//it will copy paste while person.h here.
#include<strlib.h>

int main(){
	Person * p = malloc(sizeof(Person));	//Person is typedef by typedef struct person { ...}Person;
						//So, Person is repacement for <Struct person> which is type, hence I can write, sizeof(Person);


}
