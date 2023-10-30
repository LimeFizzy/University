#include <stdio.h>

void Swap(int *a, int *b);

int main(){
    int a = 10, b = 12;
    Swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

void Swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}