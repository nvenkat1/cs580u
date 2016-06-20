#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
		char name[10];
		int age;
		char hobbies[3][50];
};
int main(){
	/*char array[3][50] = {
				{ "Nikhil", "Vijay", "Vandana" },
				{ "1111111", "2222222", "3333333" },
				{ "4444444", "5555555", "6666666" },
			};
	*/
	int i = 0, j = 0;
	for(i = 0 ; i< 3 ; i++){
		for ( j = 0 ; j < 10; j++){
	//		printf("%s\n", *(*(array + i) + j);
		}
	}
	char a[3][50];
	struct person *person1 = malloc(sizeof(struct person));
	char name1[10];

	printf("%d %d\n", sizeof(struct person), sizeof(person1));
	printf("%d %d %d\n", sizeof(a), sizeof(int), sizeof(name1));



return 0;
}
