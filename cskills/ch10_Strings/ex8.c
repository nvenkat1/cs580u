#include<stdio.h>


strcpy(char *t, char*s){
	while(*t++ = *s++);
}

int main(){
	char str1[] = "Keep india beautiful..... emigrate!";
	char str2[40];
	strcpy(str2, str1);
	printf("%s\n", str2);
return 0;
}
