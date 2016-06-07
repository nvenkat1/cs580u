#include<stdio.h>
int findNextMultiple(int number1,int number2);
void printValue(int number1,int number2,int next_multiple);
float convertFtoC(float fahrenheit);
void printTemperature(float fahrenheit,float celsius);
void fibonacci(int f0, int f1);

int main(){
	printf("Hello World!\n");

	printf("PartA\n");
	//For given value of x calculate value of expression
	float x = 2.55;
	printf("Value of Given Expression (3x^3 - 5x^2 + 6) for x=2.55 is %f\n", (3 * x * x * x) - (5 * x * x) + 6);

	//For given numbers find next multiple
	int number1 = 365, number2 = 7;
	int next_multiple1 = findNextMultiple(number1,number2);
	printValue(number1,number2,next_multiple1);

	number1 = 12258; number2 = 28;
	int next_multiple2 = findNextMultiple(number1,number2);
	printValue(number1,number2,next_multiple2);

	number1 = 996; number2 = 4;
	int next_multiple3 = findNextMultiple(number1,number2);
	printValue(number1,number2,next_multiple3);

	//Convert Fahrenheit value to Celsius value
	float fahrenheit = 100;
	float celsius = convertFtoC(fahrenheit);
	printTemperature(fahrenheit,celsius);

	fahrenheit = 32;
	float celsius1 = convertFtoC(fahrenheit);
	printTemperature(fahrenheit,celsius1);

	fahrenheit = -40;
	float celsius2 = convertFtoC(fahrenheit);
	printTemperature(fahrenheit,celsius2);

	printf("\nPartB\n");
	//Testing our Casting and how its loses values for wrong casting
	long int large_num = 9838263505978427528;
	printf("Given Large Number = 9838263505978427528\n");
	printf("Original value = %d\n", large_num);
	printf("TypeCasting to int = %d\n",(int) large_num);
	printf("TypeCasting to double = %f\n",(double) large_num);
	printf("TypeCasting to char = %c\n",(char) large_num);

	printf("\nPartC\n");
	//finding fibonacci series for first 20 numbers
	int f0 = 0, f1 = 1;
	fibonacci(f0,f1);
return 0;
}
//Function to calcualte next multiple of two given values
int findNextMultiple(int number1, int number2){
	int next_multiple = number1 + number2 - number1 % number2;
	return next_multiple;
}
//Function for printing values for given two numbers and its next multiple
void printValue(int number1, int number2, int next_multiple){
	printf("For Number1=%d, Number2=%d : next multiple=%d\n", number1,number2,next_multiple);
}
//Function to convert Fahrenheit to Celsuius
float convertFtoC(float fahrenheit){
	float celsius = (fahrenheit - 32) / 1.8;
	return celsius;
}
//Function to print from Fahrenheit to Celsius value
void printTemperature(float fahrenheit, float celsius){
	printf("%.2f Fahrenheit = %.2f Celsius\n",fahrenheit,celsius);
}
//Function to calculate fibonacci series for first 20 numbers
void fibonacci(int f0, int f1){
	int i = 3, f3 = 0;
	printf("f1=%d,f2=%d,",f0,f1);
	while(i<=20){
		f3 = f0 + f1;
		printf("f%d=%d,",i,f3);
		f0 = f1;
		f1 = f3;
		i++;
	}
	printf("\n");
}
