#include <stdio.h>

int getFactorial(int number);
int getFactorialNoRec(int number);

int main(){
    int num;
    scanf("%d", &num);
    printf("%d\n", getFactorial(num));
    printf("%d\n", getFactorialNoRec(num));
    return 0;
}

int getFactorial(int number){
    if(number <= 1){
        if(number == 1){
            return 1;
        }
        return 0;
    }
    return number * getFactorial(number - 1);
}

int getFactorialNoRec(int number){
    int factorial = 1;
    if(number < 1){
        return 0;
    }
    for(int i = 1; i <= number; ++i){
        factorial *= i;
    }
    return factorial;
}