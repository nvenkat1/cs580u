#include<stdio.h>

#define DEBUG 1
int myStrStr(char haystack[50], char niddle[50], char buffer[50]){

#ifdef DEBUG
	printf("%s\n%s\n%s\n", haystack, niddle, buffer);
#endif
	return 0;
}
