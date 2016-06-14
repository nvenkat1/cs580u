#include "person.h"//it will copy paste while person.h here.
#include "grades.h"
#include<strlib.h>

int main(){
	Person * p = malloc(sizeof(Person));	//Person is typedef by typedef struct person { ...}Person;
						//So, Person is repacement for <Struct person> which is type, hence I can write, sizeof(Person);
	enum Grade g = 2;
	setName(p,"Bob");

	free(p->name);		//clearing deepest pointer in struct first
	free(p);		//then clear struct
	p=NULL;


}
