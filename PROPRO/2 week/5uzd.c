#include <stdio.h>
#include <math.h>

int main(){
    double x, y, z;
    while(1>0){
        printf("Iveskite kintamojo x reiksme: ");
        if((scanf("%lf", &x)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis. Iveskite skaiciu formatu a.b.\n");
            while(getchar() != '\n');
        }
    }
    while(1>0){
        printf("Iveskite kintamojo y reiksme: ");
        if((scanf("%lf", &y)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis. Iveskite skaiciu formatu a.b.\n");
            while(getchar() != '\n');
        }
    }
    while(1>0){
        printf("Iveskite kintamojo z reiksme: ");
        if((scanf("%lf", &z)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis. Iveskite skaiciu formatu a.b.\n");
            while(getchar() != '\n');
        }
    }
    //a)
    printf("Lygties a atsakymas: %.2f\n", x+4*y+pow(z, 3));
    //b)
    if(z<0) z *= -1;
    printf("Lygties b atsakymas: %.2f\n", (x+sqrt(y))*(pow(z, 4)- z + 46.3));
    return 0;
}