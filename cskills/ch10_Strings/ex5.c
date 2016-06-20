#include<stdio.h>
int main(){
        char ch[] = "N";

        printf("%d %d %d %d\n", sizeof('3'),sizeof("3"), sizeof(3), sizeof(ch));
	/* Bro, size of ch is 2 byte
	b/c it has /0 character too at the end*/
return 0;
}

