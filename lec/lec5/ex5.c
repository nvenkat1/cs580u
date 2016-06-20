#include<stdio.h>
#include<stdlib.h>

struct  person{
	char name[];
	int age;
	char [3][50] hobbies;
};

//passing struct to function and returning a struct
struct foo(struct person p){		//stuct person is data type
					// struct is pass by value
}
int main(){
	char person_name[] = "Hannibal";
	int person_age = 57;
	char person_hobbies[][50] = {
					"long talks",
					"problem solving",
					"foodies"
				};

	// Struct : container | Multi Typed array.
	struct person hannibal;		//"struct person" whole is type like int.
					// hannibal  is variable name

	//initializing struct
	struct person hannibal =  { "Hannibal", 57, {
						"long talks",
						"problem soliving",
						"foodoes"
						}
				};

	//or 
	struct person hannibal;
	hannibal.name = "Hannibal";
	hannibal.age = 57;
	hannibal.hobbies = {	"long talks",
				"problem soliving",
                                "foodoes"
                             };

	//on the fly, on global space, withotu giving name
	struct{
		int i;
		char c;
	}my_data_type;
	my_data_type.i= 5;
	my_data_type.c= 'a';

	//or initialize it on the line.
        struct{
                int i;
                char c;
        }my_data_type = {5, 'a'};	//size would be 5 bytes, int 4 + char 1
	printf("size of strct %d\n",sizeof(my_data_type));
	//but it will give 8 bytes. read notebook


	//passing struct as parameter
	foo(p);

	//array pf strict
	struct person people[5];
	people[0].name = "Forrest";

	//copy directly
	people[1].name = "hannibal";

	//also all in one line directly. one after the other.
	// as struct are of same chunck when in array. 0 or array 1st element
	// all will be sequential one after the other.
	struct person people[2] = {"Forrest", 45, hobbies1, "Hannibai", 57, hobbies2};

	//strict  & malloc
	struct temp{
                int i;
                double d;
        }my_data_type;
	struct temp * sptr = malloc(sizeof(temp));
	printf("%d\n", sizeof(struct temp));	//notice type struct s
		//above size would print 16, b/c double =  8 * 2 = 12


	return 0;
}

