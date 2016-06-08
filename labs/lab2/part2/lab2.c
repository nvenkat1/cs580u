#include<stdio.h>
#include<limits.h>

int calMaskValue(){
        //unsigned int mask = 2147483648; //this is 1000 0000 0000 0000 0000 0000 0000 0000 for 32-bit machine.
        int totalBits = 8 * sizeof(int), j=0;
        int mask = 1;

        for(j=0; j< (totalBits-1) ; j++)
                mask = mask << 1;               //<< left shift is like multiplying by 2^(shift value)
        mask = ~mask;
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
        while(mask>0){
                if((number & mask)==0){ //Checking each bit , bit by bit
                        printf("0");
                }else{
                        printf("1");
                }
                mask = mask >> 1;       //Right shift by 1, means  E.g. 8 (1000) >> 1 = 4 (0100), It is like dividing by 2
                                        //Right shift by 2, means E.g. 8 (1000) >> 2 = 2 (0010),  It is like dividing by 2^2 means 4
        }
        printf("\n");
}
int main(){
        unsigned int mask = calMaskValue();
        signed int array[6] = {2, 255, 32, -1, INT_MAX, INT_MIN};
        int i = 0;

        for(i=0;i<6;i++){
                calBinaryUsingBitwise(array[i], mask);
        }
return 0;

}
