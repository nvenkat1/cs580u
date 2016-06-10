#include "myStrStr.c"
#include<stdio.h>

void printResultMessage(int result, char haystack[50], char niddle[50], char buffer[50]){
        if(result)
                printf("\tNiddle=[%s] matched with haystack=[%s]!, buffer=[%s]\n\n", niddle, haystack, buffer);
        else
                printf("\tSorry! Niddle=[%s] doens't matched with haystack=[%s], buffer=[%s]\n\n", niddle, haystack, buffer);
}
int main(){
	//char haystack[50]={0}, needle[50]={0}, buffer[50]={0};
	char buffer[50]={0};
	//FILE * fptr;
	int result = 0, i = 0;

	char *haystack[10] = {"apple","orange","blueberry","strawberry","banana","grapefruit"};
	char *niddle[10] = {"app","ge","ueber","strawberry","na","terrible"};

	for(i=0; i<6; i++){
		result = myStrStr(haystack[i],niddle[i],buffer);
		printResultMessage(result, haystack[i], niddle[i], buffer);
		memset(buffer, 0, 50);
	}
/*
	//1:
	result = myStrStr("apple", "app", buffer);
	printResultMessage(result,buffer);
	memset(buffer, 0, 50);

	//2:
	result = myStrStr("orange", "ge", buffer);
	printResultMessage(result,buffer);
	memset(buffer, 0, 50);

	//3:
	result = myStrStr("blueberry", "ueber", buffer);
	printResultMessage(result,buffer);
	memset(buffer, 0, 50);

	//4:
	result = myStrStr("strawberry", "strawberry", buffer);
	printResultMessage(result,buffer);
	memset(buffer, 0, 50);

	//5:
	result = myStrStr("banana", "na", buffer);
	printResultMessage(result,buffer);
	memset(buffer, 0, 50);

	//6:
	result = myStrStr("grapefruit", "terrible", buffer);
	printResultMessage(result,buffer);
	memset(buffer, 0, 50);
*/
	return 0;
}
