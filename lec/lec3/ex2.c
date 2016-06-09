#include<stdio.h>

void fooA();
void fooB();
void barA();
void barB();

void barB(){
	char str[]="barB";
}
void barA(){
	char str[]="barA";
	barB();
}
void fooB(){
	char str[] = "fooB";
	barA();
}
void fooA(){
	char str[] = "fooA";
	fooB();
}
int main(){
	fooA();
return 0;
}
