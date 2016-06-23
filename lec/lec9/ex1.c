#include<stdio.h>

void counter(int x){
//	int  count;
	if(x==0){
		return;
	}else{
		if(x>0){
			counter(x--);
		}else if(x<0){
			counter(x++);
		}
	}
}
int main(){

	counter(10);
	return 0;
}
