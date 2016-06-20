#include<stdio.h>

int main(){

	char * p = "Nikhil";
	char a[] ="Nikhil";

 /*Note:
	* p is address to string "Nikhil"; 
	we can reassigne *p = to soemthing else.

	but a[] has address of string "Nikhil"
	we cant reassigne that. It would be like overriding string literal
	which is not allowed.

*/
