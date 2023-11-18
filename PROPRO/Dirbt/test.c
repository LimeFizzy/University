#include <stdio.h>

int f(int x){
    if(x%5==0){
        f(x-2);
    }
    else{
        g(x-1);
    }
}

int g(int x){
    if(x>0){
        f(x);
    }
    else{
        x+=5;
    }
}

int main(){
    
    return 0;
}