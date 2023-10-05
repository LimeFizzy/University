#include <stdio.h>
#include <limits.h>

double MinNum(int n, double Numbers[]);
double MaxNum(int n, double Numbers[]);

int main(){
    int n;
    double summ=0, avg;
    printf("Programa apskaiciuoja ivestos skaiciu sekos nariu suma, vidurki, maziausia ir didziausia reiksmes.\n");
    printf("Iveskite kiek bus sekos nariu.\n");
    scanf("%d", &n);
    double Numbers[n];
    for(int i=0; i<n; ++i){
        printf("Iveskite %d-aji sekos nari:\n", i+1);
        scanf("%lf", &Numbers[i]);
        summ += Numbers[i];
    }
    avg = summ/n;

    printf("Ivestos skaiciu sekos summa = %.2lf, vidurkis = %.2lf, minimumas = %.2lf, maksimumas = %.2lf.\n", summ, avg, MinNum(n, Numbers), MaxNum(n, Numbers));
    return 0;
}

double MinNum(int n, double Numbers[]){
    double min = INT_MAX;
    for(int i=0; i<n; ++i){
        if(Numbers[i]<min) 
            min = Numbers[i];
    }
    return min;
}

double MaxNum(int n, double Numbers[]){
    double max = INT_MIN;
    for(int i=0; i<n; ++i){
        if(Numbers[i]>max) 
            max = Numbers[i];
    }
    return max;
}