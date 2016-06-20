#include<stdio.h>
int main(){
	char *str1 ="Hello";
	char *str2 ="Hello";
	char str3[] ="Hello";
	char str4[] ="Hello";

	printf("%s %s\n", str1, str2);
	printf("%s %s\n", *str1, *str2);
	printf("%s %s\n", str3, str4);

	if( str1 == str2 )
	        printf("Equal\n");
	else
	        printf("Un-Equal\n");

	if( str3 == str4 )
	        printf("Equal\n");
	else
	        printf("Un-Equal\n");

;

return 0;
}
