#include <stdio.h>
#include <assert.h>
#include <limits.h>

unsigned long fact(unsigned char n){
    if(n < 0){
        return 0;
    }
    if(n == 1 || n == 0){
        return 1;
    }
    return n * fact(n - 1);
}

unsigned long factnoRec(unsigned char n){
    unsigned long factorial = 1;
    if(n < 0){
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        factorial *= i;
    }
    return factorial;
}

int main(){
    assert(fact(5) == 120);
    assert(fact(2) == 2);
    assert(fact(10) == 3628800);
    assert(fact(1) == 1);
    assert(fact(0) == 1);
    return 0;
}