#include <stdio.h>

int main(){
    int sk;
    //Decimal to hexadecimal
    scanf("%d", &sk);
    printf("\n0x%x", sk);
    //Hexadecimal to decimal
    scanf("%x", &sk);
    printf("\n%d", sk);
    return 0;
}