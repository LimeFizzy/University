#include <stdio.h>
#include <math.h>

int main(){
    double x, y, z;
    do
    {
        printf("Iveskite kintamojo x reiksme: ");
    } while (scanf("%lf", &x)!=1 && getchar()!='\n');
    do
    {
        printf("Iveskite kintamojo y reiksme: ");
    } while (scanf("%lf", &y)!=1 && getchar()!='\n');
    do
    {
        printf("Iveskite kintamojo z reiksme: ");
    } while (scanf("%lf", &z)!=1 && getchar()!='\n');
    //a)
    printf("Lygties a atsakymas: %.2f\n", x+4*y+pow(z, 3));
    //b)
    if(z<0) z *= -1;
    printf("Lygties b atsakymas: %.2f\n", (x+sqrt(y))*(pow(z, 4)- z + 46.3));
    return 0;
}