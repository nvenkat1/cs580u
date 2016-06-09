#include "myStrStr.c"
#include<stdio.h>

int main(){
	//char haystack[50]={0}, needle[50]={0}, buffer[50]={0};
	char buffer[50]={0};
	//FILE * fptr;
	int result = 0;
	result = myStrStr("apple", "app", buffer);
	if(result) printf("%s",buffer);
	result = myStrStr("orange", "ge", buffer);
	if(result) printf("%s",buffer);
	result = myStrStr("blueberry", "ueber", buffer);
	if(result) printf("%s",buffer);
	result = myStrStr("strawberry", "strawberry", buffer);
	if(result) printf("%s",buffer);
	result = myStrStr("banana", "na", buffer);
	if(result) printf("%s",buffer);
	result = myStrStr("grapefruit", "terrible", buffer);
	if(result) printf("%s",buffer);
	return 0;
}
