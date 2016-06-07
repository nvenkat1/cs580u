#include<stdio.h>
#include<limits.h>

void calculateBinaryMask(int number){
	unsigned int mask = 2147483648; //this is 1000 0000 0000 0000 0000 0000 0000 0000 for 32-bit machine. 
	//we start with anding given number with mask value
	//Now mask value has only MSB bit as 1.
	//Hence adding with any number's MSB value will show us that,
	//given number is positive or negative
	printf("Binary Representation of %d:\n",number);
	while(mask>0){
		if((number & mask)==0){	//Checking each bit , bit by bit
			printf("0");
		}else{
			printf("1");
		}
		mask = mask >> 1;	//Right shift by 1, means  E.g. 8 (1000) >> 1 = 4 (0100), It is like dividing by 2
					//Right shift by 2, means E.g. 8 (1000) >> 2 = 2 (0010),  It is like dividing by 2^2 means 4
	}
	printf("\n");


}
int isNegative(int number){
	return number<0;

}
void calculateBinary(int number){
	int stack[32];
	int quotient=-1,reminder=-1,i=0,j=0;
	int flagNegative = isNegative(number);
	//if(flagNegative)
	//	printf("Negative Value");

	printf("Binary Representation of %d:\n",number);
	while(quotient!=0){
		quotient = number / 2;
		reminder = number % 2;
		//printf("Quotient=%d\t Reminder=%d\n",quotient,reminder);
		stack[i]= reminder;
		number = quotient;
		i++;
	}
	//printf("Value of i=%d\n\n",i);
	for(j=i;j<32;j++){
		stack[j]=0;
		//printf("Stack[%d] = %d\n",j,*(stack+j));
	}
	//printf("Printing values:");
	//printf("%d ",i+1);
	for(i=31;i>=0;i--){
		printf("%d",stack[i]);
		if(i%4 ==0){
			printf("  ");
		}
	}
	printf("\n");
}

int main(){
	int a = 8;
	//printf("Size of int=%x bytes\n",sizeof(int));
	//size of int is 4 byes = 32 bits.
	//int mask = 2147483648; //this is 1000 0000 0000 0000 0000 0000 0000 0000 for 32-bit machine. 

	int array[6] = {2,255,32,-1,INT_MAX,INT_MIN},i=0;

	//###Testing printing array####
	//for(i=0;i<6;i++){
	//	printf("Array[%d] = %u\n",i+1, *(array+i));
	//}

	for(i=0;i<6;i++){
		calculateBinary(array[i]);
	}
	printf("\n\n");

	for(i=0;i<6;i++){
		calculateBinaryMask(array[i]);
	}
return 0;

}
