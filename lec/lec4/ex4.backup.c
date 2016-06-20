#include<stdio.h>
#define PART1 0
#define PART2 1
#define PART3 0
#define PART4 0


int main(){

#if PART1
	//try1
	char buf[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fscanf(fptr, "%s", &buf);
	printf("%s\n", buf);
	fscanf(fptr, "%s", &buf);
	printf("%s\n", buf);

#endif

#if PART2
	//try2 : flush the buffer using fclose();
	char buf1[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fscanf(fptr, "%s", &buf1);
	fprintf(fptr,"%s\n", buf1);
	fscanf(fptr, "%s", &buf1);
	fprintf(fptr, "%s\n", buf1);
	int * x = 0;
	//*x;
	//solution:fclose();

#endif

#if PART3
	//try 3
	char buf2[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fgets(buf2, 50 , fptr);
	fscanf(fptr, "%s", &buf2);
	fprintf(fptr,"%s\n", buf2);
	fscanf(fptr, "%s", &buf2);
	fprintf(fptr, "%s\n", buf2);

	solution:fclose();

#endif

#if PART4

	//try 4: use of fseek()
	char buf[51] = {0};
	FILE * fptr = fopen("ex4.c", "r");
	fgets(buf, 50 , fptr);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr,"%s\n", buf);
	fscanf(fptr, "%s", &buf);
	fprintf(fptr, "%s\n", buf);
	fseek(fptr, -3, SEEK_SET);

#endif
	//we have SEEK_SET = start position 
	// SEEK_CUR = current position
	// SEEK_END = end position.

return 0;
}
