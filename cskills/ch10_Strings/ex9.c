#include<stdio.h>
#include<string.h>

int main(){
        char *str[] = {"Frong","Do","Not","Die","They","Crock!"};

        printf("sizeof(str) =%d sizeof(str[0] =%d \n", sizeof(str),sizeof(str[0]));
        printf("len(str) =%d len(str[0] =%d \n", strlen(str),strlen(str[0]));

	//*str[] is array of pointers.
	//pointer size on 32 bit machine is 8 bytes.
	//str[] has 6 elements of pointers.
	//total 48 bytes

	//str[0] has pointer again, to first string
	//hence size would be 8 bytes for 32 bit machine

	//str length I dont know. why its 3, we are asking for calculate leng
	//for **str.. could be wrong.
	//strlen(str[0]) maks sense, it will give length of first element
	//which is  5. 

return 0;
}

