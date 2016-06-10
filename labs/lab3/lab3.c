/*Lab3 = https://docs.google.com/document/d/1vuv4mhqKt9d8I-itucQC6GhfU72boZ_D8gnVDQPeOtg/edit#heading=h.t5j2u7kdrqni*/
#include "myStrStr.c"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define PART1 1
#define PART2A 1
#define PART2B 1

void splitString(char firstName[20], char lastName[20], char buffer[50]){
#if DEBUG
	printf("In spilt %s\n",buffer);
	printf("Buffer length = %d | Buffer[0]=%c | Buffer[1]=%c", strlen(buffer), buffer[0], buffer[1]);
#endif
	//Bagde,Nikhi l
	//01234567891011  total[0-11] 12

	int flagAfterComma = 0, commaPosition = 0, flagBlankFound = 0, i;
	for( i = 0; i<strlen(buffer); i++){
		//assumption, FN and LN are seperated by only (,) and stictly not by ' ' or '\n'
		if(buffer[i] == ' ' || buffer[i] == '\n'){
			flagBlankFound = 1;
			break;
		}
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

/*Formatting buffer*/
void formatBuffer(char buffer[50]){
	int i = 0;
	if(buffer[0]!='\0'){
		/*while(i<strlen(buffer)){
			buffer[i] = tolower(buffer[i]);
		i++;
		}*/
		for(i = 0; i< strlen(buffer); i++){
			buffer[i] = tolower(buffer[i]);
		}
		buffer[0] = toupper(buffer[0]);
	}
#if DEBUG
	printf("In Formatbuffer: buffer=%s\n", buffer);
#endif
}
/*Find jedi name: BagNi
	Take the first 3 letters of your last name = Bagde = Bag
	Add the first 2 letters of your first name = Nikhil = Ni
*/
void findJediName(char* firstName, char* lastName, char buffer[50]){
#if DEBUG
	printf("In findJediName: FN=%s LN=%s\n", firstName, lastName);
#endif
	if(firstName[0]!='\0' && lastName[0]!='\0'){
		int i = 0, j = 0;

		for(i=0; i<5; i++){
			if(strlen(lastName)<3){			//Case: When LN is less than size 3,
				if(i<2){
					buffer[i]=lastName[i];
				}else if(i<4){
					buffer[i]=firstName[i-2];	//need to start from 0 for FN, so negate previous index value of i, which will be i=2.
				}
			}else{
				if(i<3){
					buffer[i]=lastName[i];
				}else if(i<5){
					buffer[i]=firstName[i-3];	//need to start from 0 for FN. So (i-3)
				}
			}
		}
	}
	//to format in : Abcdedg (only first letter in Uppercase)
	formatBuffer(buffer);
#if DEBUG
	printf("In findJediName: Buffer = %s\n",buffer);
#endif
}

/*Prints out message wheather string is matched or not*/
void printResultMessage(int result, char haystack[50], char niddle[50], char buffer[50]){
        if(result)
                printf("\t|Niddle=%-15s |haystack=%-15s |buffer=%-15s = Matched!\n", niddle, haystack, buffer);
        else
                printf("\t|Niddle=%-15s |haystack=%-15s |buffer=%-15s = No Match!\n", niddle, haystack, buffer);
}
int main(){
	char buffer[50]={0};

#if PART1
	//Part 1 -- String Manipulations
	printf("\t----Part1- String Manipulation----\n");
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
	printf("\t----Part 2: What's Our Jedi Name----\n\t--Part A: Your Jedi Name--\n");
	findJediName("nikhil", "bagde", buffer);
	printf("\tMy JediName = %s\n\n", buffer);
	memset(buffer, 0, 50);

#endif

#if PART2B
	//Part B: Classmates jediname list
	printf("\t--Part B: Classmates Jediname List--\n\n");
	char firstName[20]={0}, lastName[20]={0};
	FILE * fptr = fopen("name.txt","r");
#if DEBUG
	//fscanf(fptr,"%s", buffer);
	//printf("%s\n",buffer);
#endif
	while(fscanf(fptr, "%s", buffer)!=EOF){
		splitString(firstName, lastName, buffer);
#if DEBUG
		printf("In main after call, lastname= %s, firstName=%s\n", lastName, firstName);
#endif
		memset(buffer, 0, 50);
		findJediName(firstName, lastName, buffer);
		if(buffer[0]!='\0')
			printf("\t|First:%-15s\t|Last:%-15s\t|JediName:%-5s\n",firstName, lastName, buffer);
		memset(buffer, 0, 50);
		memset(firstName, 0, 20);
		memset(lastName, 0, 20);
	}
	fclose(fptr);
#endif//PART2B
	return 0;
}
