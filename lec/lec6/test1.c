
#include<stdio.h>

func3(int * three){
        three = 33333;
        return (int) three;
}
func2(int * two){
        (*two) = 22222;
        return func3(two);
}

func1(int * one){
        (*one) = 11111;
        return func2 (one);
}
int main(){
        int zero = 0;
        int rvalue = zero;
        int lvalue = func1(&zero);
        printf("rvalue %d\n", zero);
        printf("lvalue %d\n", lvalue);
return 0;
}
