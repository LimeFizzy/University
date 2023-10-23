#include <stdio.h>

int isInRange(int number, int low, int high);

int main(){
    int min, max, num;
    printf("Programa tikrina ar ivestas skaicius papuola i intervala.\n");
    printf("Iveskite intervalo minimuma, maksimuma ir norima skaiciu.\n");
    scanf("%d %d %d", &min, &max, &num);
    if(isInRange(num, min, max)){
        printf("True.\n");
    }
    else{
        printf("False.\n");
    }
    return 0;
}

int isInRange(int number, int low, int high){
    if(low > high){
        return 0;
    }
    else if(number >= low && number <= high){
        return 1;
    }
    return 0;
}