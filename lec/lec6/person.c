#include<stdio.h>
#include<stdlib.>
void setName(struct *person, char *name){
	//person.name = name;
	person.name = malloc(255);	//will have to free name also.
	//strcpy(p.name,name);
	int i=0;
	while( *(name)! = NULL){
		person->name[i] = *name;
		i++;
		name++;
	}
	/*Alternative to above while
	while( (*person).name[i]++ = *name++) ;
	*/
}
