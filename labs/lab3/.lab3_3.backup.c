/*Lab3 = https://docs.google.com/document/d/1vuv4mhqKt9d8I-itucQC6GhfU72boZ_D8gnVDQPeOtg/edit#heading=h.t5j2u7kdrqni*/
#include "myStrStr.c"
#include<stdio.h>
#include<string.h>

#define PART1 0
#define PART2 1

/*Find jedi name: BagNi
	Take the first 3 letters of your last name = Bagde = Bag
	Add the first 2 letters of your first name = Nikhil = Ni
*/
void findJediName(char* firstName, char* lastName, char buffer[50]){
#if DEBUG
	printf("%s\n", firstName);
#endif
	int i = 0, j = 0;
	char jediName[20];

	for(i=0; i<5; i++){
		if(i<3){
			jediName[i]=lastName[i];
			buffer[i]=lastName[i];

		}else if(i<5){
			jediName[i]=firstName[i-3];
			buffer[i]=firstName[i-3];
		}
	}
	printf("My JediName = %s\n",jediName);
	printf("My Buffer = %s\n",buffer);
	//return &(jediName[0]);

}

/*Prints out message wheather string is matched or not*/
void printResultMessage(int result, char haystack[50], char niddle[50], char buffer[50]){
        if(result)
                printf("\tNiddle=[%s] matched with haystack=[%s], buffer=[%s]\n\n", niddle, haystack, buffer);
        else
                printf("\tSorry! Niddle=[%s] doens't matched with haystack=[%s], buffer=[%s]\n\n", niddle, haystack, buffer);
}
int main(){
	char buffer[50]={0};

#if PART1
	//Part 1 -- String Manipulations
	int result = 0, i = 0;

	char *haystack[10] = {"apple","orange","blueberry","strawberry","banana","grapefruit"};
	char *niddle[10] = {"app","ge","ueber","strawberry","na","terrible"};

	for(i=0; i<6; i++){
		result = myStrStr(haystack[i],niddle[i],buffer);
		printResultMessage(result, haystack[i], niddle[i], buffer);
		memset(buffer, 0, 50);
	}
#endif

#if PART2
	//Part 2: What’s Our Jedi Name
	//char jediName=[20];
	findJediName("Nikhil", "Bagde", buffer);
	printf("In Main, buffer = %s", buffer);
#endif
	return 0;
}
