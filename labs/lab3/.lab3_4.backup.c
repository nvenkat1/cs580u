/*Lab3 = https://docs.google.com/document/d/1vuv4mhqKt9d8I-itucQC6GhfU72boZ_D8gnVDQPeOtg/edit#heading=h.t5j2u7kdrqni*/
#include "myStrStr.c"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define PART1 0
#define PART2A 0
#define PART2B 1

void splitString(char firstName[20], char lastName[20], char buffer[50]){
#if DEBUG
	printf("In spilt %s\n",buffer);
	printf("Buffer length = %d\n", strlen(buffer));
#endif
	//Bagde,Nikhi l
	//01234567891011  total[0-11] 12

	int flagAfterComma = 0, commaPosition = 0;
	for( i = 0; i<strlen(buffer); i++){
		if(buffer[i] == ','){
			flagAfterComma = 1;
			commaPosition = i;
			continue;
		}
		if(flagAfterComma){
			firstName[i-(commaPosition+1)] = buffer[i];
		}else{
			lastName[i] = buffer[i];
		}
	}
#if DEBUG
	printf("Using (int i) lastname = %s  firstName=%s\n\n",lastName, firstName);
#endif


}
/*Find jedi name: BagNi
	Take the first 3 letters of your last name = Bagde = Bag
	Add the first 2 letters of your first name = Nikhil = Ni
*/
void findJediName(char* firstName, char* lastName, char buffer[50]){
#if DEBUG
	printf("%s\n", firstName);
#endif
	int i = 0, j = 0;

	for(i=0; i<5; i++){
		if(i<3){
			buffer[i]=lastName[i];

		}else if(i<5){
			buffer[i]=firstName[i-3];
		}
	}
#if DEBUG
	printf("My Buffer = %s\n",buffer);
#endif
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

#if PART2A
	//Part 2: What’s Our Jedi Name
	//Part A: Your jediname
	findJediName("nikhil", "bagde", buffer);
	buffer[0] = toupper(buffer[0]);
	printf("My JediName = %s\n", buffer);
	memset(buffer, 0, 50);

#endif

#if PART2B
	//Part B: Classmates jediname list
	char firstName[20]={0}, lastName[20]={0};

	FILE * fptr = fopen("name.txt","r");

#if DEBUG
	//fscanf(fptr,"%s", buffer);
	//printf("%s\n",buffer);
#endif

	while(fscanf(fptr, "%s", buffer)!=EOF){
		splitString(firstName, lastName, buffer);
#if DEBUG
		printf("In main after call\n, lastname= %s, firstName=%s\n", lastName, firstName);
#endif
		memset(buffer, 0, 50);
		findJediName(firstName, lastName, buffer);
		printf("\tFirst:%s\tLast:%s\tJediName:%s\n",firstName, lastName, buffer);
		memset(buffer, 0, 50);
		memset(firstName, 0, 20);
		memset(lastName, 0, 20);

	}

#if DEBUG
	while(fscanf(fptr, "%s", buffer)!=EOF){
		//char readChar;
		//if(fscanf(fptr,"%c",&readChar) == "\n")
		printf("%s\t", buffer);
	}
#endif

#endif//PART2B
	return 0;
}
