#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){
        char str4[] = "United";
        char str41[20] = "United";
        char str5[] = "Front";
        char str6[20] = {""};

	strcat(str41,str5);
	printf("str41= (str41,str5) = %s\n", str41);

	strcat(str4,str5);
	printf("str4 = (str4,str5) = %s\n", str4);

	printf("str6 = %s\n", str6); //it will print blank

	strcat(str6, str4);
	printf("str6 = (str6, str4) = %s\n", str6);//it will print str6+str4 = "United"

	strcat(str6, str5);
	printf("str6 = (str6, str5) = %s\n", str6);//it will print str6+str5 = "United Front"

	//str6 = strcat(str4, str5);
	//you cant do this, as you are overriting to str 4

	//by contactenation str 5 to str4, and storing it to str4 again.
	//strcat(*Destination,*source);
	//that means destination always should be blank stirng

	printf("%s\n", str4);
	printf("%s\n", str5);
	printf("%s\n", str6);
	printf("\n\n ***");
        char *str1 = "United";
        char *str2 = "Front";

        //char *str3 = malloc( strlen(str1) + strlen(str2) + 1);
	//str3 = strcat(str1, str2); wrong! copying back to str1.
	strcat(str3, str1);
	strcat(str3, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);

return 0;
}

