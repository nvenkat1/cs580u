#include<stdio.h>
int main(){
	int integer1=0;
	char character1='\0';
	float float1=0.0;
	double double1=0.0;
	long long1=0;
	
	int arrayInt[5] = {1,2,3,4,5};
	long arrayLong[5] = {100,200,300,400,500};
	char arrayChar[5] = {'a','b','c','d','e'};
	float arrayFloat[5] = {1.1,2.2,3.3,4.4,5.5};
	double arrayDouble[5] = {1.11,2.22,3.33,4.44,5.55};
	
	printf("integer1=%d\n", integer1);
	printf("character1=%c\n", character1);
	printf("float=%f\n", float1);
	printf("long=%d\n", long1);

	printf("Size of Int = %d\n", sizeof(integer1));
	printf("Size of Char = %d\n",sizeof(character1));
	printf("Size of Float = %d\n", sizeof(float1));
	printf("Size of Double = %d\n", sizeof(double1));
	printf("Size of Long = %d\n",sizeof(long1));
	
	printf("Size of arrayInt = %d\n", sizeof(arrayInt));
	printf("Size of arrayLong = %d\n", sizeof(arrayLong));
	printf("Size of arrayChar = %d\n", sizeof(arrayChar));
	printf("Size of arrayFloat = %d\n", sizeof(arrayFloat));
	printf("Size of arrayDouble = %d\n", sizeof(arrayDouble));	
	
	printf("Address of ArrayInt = %u\n", &arrayInt);
	printf("Address of First element of ArrayInt = %u\t %x\t %p\n", &arrayInt+0, &arrayInt+0, &arrayInt+0);
	printf("Address of Second element of ArrayInt = %u\t %x\t %p\n", &arrayInt+1, &arrayInt+1, &arrayInt+1);
	printf("Address of Third element of ArrayInt = %u\t %x\t %p\n", &arrayInt+2, &arrayInt+2, &arrayInt+2);
	printf("Address of Forth  element of ArrayInt = %u\t %x\t %p\n", &arrayInt+3, &arrayInt+3, &arrayInt+3);
	printf("Address of Fifth element of ArrayInt = %u\t %x\t %p\n", &arrayInt+4, &arrayInt+4, &arrayInt+4);
	printf("Address of Sixth element of ArrayInt = %u\t %x\t %p\n\n", &arrayInt+5, &arrayInt+5, &arrayInt+5);

	printf("Address of First element of ArrayChar = %u\t %x\t %p\n", &arrayChar+0, &arrayChar+0, &arrayChar+0);
	printf("Address of Second element of ArrayChar = %u\t %x\t %p\n", &arrayChar+1, &arrayChar+1, &arrayChar+1);
	printf("Address of Third element of ArrayChar = %u\t %x\t %p\n", &arrayChar+2, &arrayChar+2, &arrayChar+2);
	printf("Address of Forth element of ArrayChar = %u\t %x\t %p\n", &arrayChar+3, &arrayChar+3, &arrayChar+3);
	printf("Address of Fifth element of ArrayChar = %u\t %x\t %p\n", &arrayChar+4, &arrayChar+4, &arrayChar+4);
	printf("Address of Sixth element of ArrayChar = %u\t %x\t %p\n\n", &arrayChar+5, &arrayChar+5, &arrayChar+5);

	printf("Address of First element of ArrayLong = %u\t %x\t %p\n", &arrayLong+0, &arrayLong+0, &arrayLong+0);
	printf("Address of Second element of ArrayLong = %u\t %x\t %p\n", &arrayLong+1, &arrayLong+1, &arrayLong+1);
	printf("Address of Third element of ArrayLong = %u\t %x\t %p\n", &arrayLong+2, &arrayLong+2, &arrayLong+2);
	printf("Address of Forth element of ArrayLong = %u\t %x\t %p\n", &arrayLong+3, &arrayLong+3, &arrayLong+3);
	printf("Address of Fifth element of ArrayLong = %u\t %x\t %p\n", &arrayLong+4, &arrayLong+4, &arrayLong+4);
	printf("Address of Sixth element of ArrayLong = %u\t %x\t %p\n\n", &arrayLong+5, &arrayLong+5, &arrayLong+5);

	printf("Address of First element of ArrayDouble = %u\t %x\t %p\n", &arrayDouble+0, &arrayDouble+0, &arrayDouble+0);
	printf("Address of Seocond element of ArrayDouble = %u\t %x\t %p\n", &arrayDouble+1, &arrayDouble+1, &arrayDouble+1);
	printf("Address of Third element of ArrayDouble = %u\t %x\t %p\n", &arrayDouble+2, &arrayDouble+2, &arrayDouble+2);
	printf("Address of Forth element of ArrayDouble = %u\t %x\t %p\n", &arrayDouble+3, &arrayDouble+3, &arrayDouble+3);
	printf("Address of Fifth element of ArrayDouble = %u\t %x\t %p\n", &arrayDouble+4, &arrayDouble+4, &arrayDouble+4);
	printf("Address of Sixth element of ArrayDouble = %u\t %x\t %p\n\n", &arrayDouble+5, &arrayDouble+5, &arrayDouble+5);
	
	printf("Address of First element of ArrayFloat = %u\t %x\t %p\n", &arrayFloat+0, &arrayFloat+0, &arrayFloat+0);
	printf("Address of Second element of ArrayFloat = %u\t %x\t %p\n", &arrayFloat+1, &arrayFloat+1, &arrayFloat+1);
	printf("Address of Third element of ArrayFloat = %u\t %x\t %p\n", &arrayFloat+2, &arrayFloat+2, &arrayFloat+2);
	printf("Address of Forth element of ArrayFloat = %u\t %x\t %p\n", &arrayFloat+3, &arrayFloat+3, &arrayFloat+3);
	printf("Address of Fifth element of ArrayFloat = %u\t %x\t %p\n", &arrayFloat+4, &arrayFloat+4, &arrayFloat+4);
	printf("Address of Sixth element of ArrayFloat = %u\t %x\t %p\n\n", &arrayFloat+5, &arrayFloat+5, &arrayFloat+5);

return 0;
}
