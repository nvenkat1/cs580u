#ifdef PERSON_H
#define PERSON_H

//1
//enum Grade{A,B,C,D,F}	//no semicolon : normally add enum to hearder file
				//b/c as it is just like type def
//2
//Glbal veriable : should go to header file
//only if it is uninitialized
//int bad_global;


//3
typedef struct person{	char * name;
			int age;
			double grade;
			} Person;
//typedef <type> <name>
//type = struct person{...}
//name = Person

//4 : function declaration
//all function realted to person, we can add it to header file
void setName(Person *p, char * name);


//5: Never ever include implemenation of any function in header file.
//it should always go in .c files.
//header file is only for declaration.

#endif
