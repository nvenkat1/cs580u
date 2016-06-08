#include<stdio.h>

int main(){
	//try1
	char buf[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fscanf(fptr, "%s", &buf);
	printf("%s\n", buf);
	fscanf(fptr, "%s", &buf);
	printf("%s\n", buf);

	//try2 : flush the buffer using fclose();
	char buf[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fscanf(fptr, "%s", &buf);
	fprintf(fptr,"%s\n", buf);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr, "%s\n", buf);
	int * x = 0;
	*x;
	//solution:fclose();

	//try 3
	char buf[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fgets(buf, 50 , fptr);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr,"%s\n", buf);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr, "%s\n", buf);
	
	solution:fclose();

	//try 4: use of fseek()
	char buf[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fgets(buf, 50 , fptr);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr,"%s\n", buf);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr, "%s\n", buf);
	fseek(fptr, -3, SEEK_SET);

	//we have SEEK_SET = start position 
	// SEEK_CUR = current position
	// SEEK_END = end position.

return 0;
}
