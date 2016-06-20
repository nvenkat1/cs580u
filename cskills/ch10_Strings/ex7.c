#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	char str1[20] = "United";
	char *str2 = "Nations";
	char *str3;
	str3 = strcat(str1,str2);
	printf("%s\n", str3);
return 0;
}
