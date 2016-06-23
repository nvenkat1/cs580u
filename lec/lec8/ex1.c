#include<stdio.h>

typedef struct train{
	struct car * engine;
}Train;

typedef struct car{
	float weight;
	struct car * next;
	int lastCarFlag;
}Car;

float calTotalWeight(Train * train){
	int count = 0;
	while( (*((*train).next).next).lastCarFlag != 0){
		return count ++;
	}
}
int main(){

	Train * train = malloac(sizeof(Train));
	Car * cart1 = malloac(sizeof(Car));
	Car * cart2 = malloac(sizeof(Car));
	Car * cart3 = malloac(sizeof(Car));

	(*cart1).weight = 567.8;
	(*cart2).weight = 123.4;
	(*cart3).weight = 789.0;

	(*train).engine = cart1;
	(*cart1).next = cart2;
	(*cart2).next = cart3;
	(*cart3).lastCarFlag = 1;

	float totalWeight = calTotalWeight(train);
	return 0;
}

