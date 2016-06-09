#include<stdio.h>
#include<limits.h>
#include<stdlib.h> 	/* srand, rand */
#include<time.h>       /* time */

//Signed value rang  1.  [0 to 2,147,483,648-1=2147483647] = [0-2147483647] positive numbers [0 to (2^32/2)-1]
//		     2.  [-2147483648 = above number  1000 ...00 000 0000 0000 0000 0000 = -2147483648(used to mask 31st  bit of any number)
//			next number 		     +                                1
//						    ______________________________________
//						    1000 0000 00000 0000 0000 0000 0001 = -2147483647,-2147483646,.....,-1 (negative values)
//		     2.	so, [-2147483648 to -1] negative values [(2^32/2) to -1]
//		     3. Total = 4294967296 = 2 ^ 32
//reference: https://github.com/cs3157/recitations/blob/master/D-Bits-Binary-C-Basics/bits-binary-and-c-basics.md


//Calculate  mask value to for given machine dynamically

int calMaskValue(){
        //unsigned int mask = 2147483648; //this is 1000 0000 0000 0000 0000 0000 0000 0000 for 32-bit machine.
        int totalBits = 8 * sizeof(int), j=0;
        unsigned int mask = 1;

        for(j=0; j< (totalBits-1) ; j++)
                mask = mask << 1;               //<< left shift is like multiplying by 2^(shift value)
        //mask = ~mask;
        //mask = mask + 1;

        printf("Total bits in your machine for int =  (8 * sizeof(int)) = %d bits\n", totalBits);
        printf("Calculated mask is = %d\n", mask);
        return mask;

}

//we start with anding given number with mask value
//Now mask value has only MSB bit as 1.
//Hence adding with any number's MSB value will show us that,
//given number is positive or negative

void calBinaryUsingBitwise(int number,unsigned int mask){

        printf("Binary Representation of %d:\n",number);
	int counterForAddingSpace = 0;
        while(mask>0){
                if((number & mask)==0){ //Checking each bit , bit by bit
                        printf("0");
                }else{
                        printf("1");
                }
                mask = mask >> 1;       //Right shift by 1, means  E.g. 8 (1000) >> 1 = 4 (0100), It is like dividing by 2
                                        //Right shift by 2, means E.g. 8 (1000) >> 2 = 2 (0010),  It is like dividing by 2^2 means 4
		counterForAddingSpace++;
		if(counterForAddingSpace %4 == 0)	//add space after each 4 bits
			printf("  ");
        }
        printf("\n");
}
int main(){
	//Part A: Binary Printer
	printf("___________PartA__________\n");
        unsigned int mask = calMaskValue();
        signed int array[6] = {2, 255, 32, -1, INT_MAX, INT_MIN};
        int i = 0;

        for(i=0;i<6;i++){
                calBinaryUsingBitwise(array[i], mask);
        }

	//Part B: Printing A Random Binary Value
	printf("___________PartB__________\n");
	/* initialize random seed: */
  	srand (time(NULL));

	/* generate secret number between maximum integer number on machine and minimum int on machine: */
	int iSecret = rand() % INT_MAX + INT_MIN;
	printf("Generating Random Number: %d\n",iSecret);
	calBinaryUsingBitwise(iSecret, mask);
return 0;

}
