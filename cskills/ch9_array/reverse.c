#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * reverse(char c[]){
	char * new_string = malloc(sizeof(c) + 1);
	int i = 0 , j = strlen(c) - 1 ;
	while( i < strlen(c)){
		*(new_string + i) = *( c + j);
		i++;
		j--;
	}
return new_string;
}

int main(){
	char name[] = "Nikhil";
	char *newString = reverse(name);
	printf("%s\n", newString);
}
