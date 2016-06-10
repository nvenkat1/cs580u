#include<stdio.h>
#include<string.h>

#define DEBUG 0

int myStrStr(char haystack[50], char niddle[50], char buffer[50]){

#if DEBUG
	printf("\t*** hay[%s]: Size=%d, nid[%s]:Size=%d, buf[%s]:Size=%d\n", haystack, strlen(haystack), niddle, strlen(niddle), buffer, strlen(buffer));
#endif
	int i = 0, j = 0, k = 0, storeIndex = 0, flagContinuation = 0;
	buffer[50] = 0;
	for(i=0; i<strlen(niddle); i++){
		char c = niddle[i];
#if DEBUG
		printf("\tniddle [%d] =  '%c' ",i,c);
#endif
		for(j = storeIndex; j<strlen(haystack); j++){
			if(c == haystack[j]){
#if DEBUG
				printf("Matched!, haystack's [%d] = '%c'\n", j, haystack[j]);
				printf("\tStored index=%d\n",j);
#endif

				buffer[k] = haystack[j];	//TODO:later try to combine  k++
				k++;
				storeIndex = ++j;
				flagContinuation = 1;
				break;
			}else{
				flagContinuation = 0;
				continue;
			}
		}//haystack for
#if DEBUG
		printf("\n");					//added to format debugging when 2nd for loop desnt execute, first print of niddle was not formatter. adding \n in case 2nd for loop if never executes.
#endif
	}//niddle for
#if DEBUG
	printf("\n\tBuffer = %s\n\n", buffer);
#endif
	return (strlen(buffer)==strlen(niddle) ? 1:0);
}
