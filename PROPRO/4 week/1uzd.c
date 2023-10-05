#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c, D, x1, x2;
    printf("Programa sprendzia kvadratines lygtis.\n");
    printf("Iveskite lygties koeficientus a, b ir c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Ivestis sekmingai irasyta.\n");

    if(a!=0){
        D = sqrt(pow(b,2) - 4*a*c);
        if(D>0){
            x1 = (-b+D) / (2.0*a);
            x2 = (-b-D) / (2.0*a);
            printf("Yra 2 sprendimai: %.2lf ir %.2lf\n", x1, x2);
        }
        else if(D==0){
            x1 = -b / (2.0*a);
            printf("Yra 1 sprendimas: %.2lf\n", x1);
        }
        else 
            printf("Sprendiniu nera.\n");
    }
    else   
        printf("Sprendiniu nera.\n");

    return 0;
}