#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Validation(char number[]);
int CountNumbers(char number[]);

int main(){
    printf("Si programa nuskaito realu skaiciu [10;1000] su nedaugiau nei 3 sk po kablelio is failo in.txt ir atspausdina jo ilgi.\n");
    FILE* input = fopen("in.txt", "r");
    if(input == NULL){
        printf("Nepavyko atidaryti failo.\n");
        return 0;
    }
    else{
        printf("Failas sekmingai atidarytas.\n");
        char number[10] = {0};
        fscanf(input, "%s", &number);
        if(Validation(number)==0){
            printf("Jusu skaicius yra %s , o jo ilgis %d.\n", number, CountNumbers(number));
        }
        else{
            printf("Bandykite is naujo. Skaicius turi atitikti reziams [10;1000] ir tureti iki 3 skaitmenu po kablelio.\n");
        }
    }
    return 0;
}

int Validation(char number[]){
    for(int i=0; number[i]!='\0'; ++i){
        if(number[i] == ','){
            int counterAfterDec = 0;
            while(isdigit(number[i+1])){
                ++i;
                ++counterAfterDec;
            }
            if(counterAfterDec > 3){
                printf("Neteisinga ivestis. Iveskite skaiciu kuris > 10 ir < 1000, bei turi iki 3 skaitmenu po kablelio.\n");
                return 1;
            }
            
            double num;
            if(sscanf(number, "%lf", &num)==1){
                if(num > 10 && num < 1000){
                    printf("Skaicius sekmingai nuskaitytas!\n");
                    return 0;
                }
                else{
                    printf("Skaicius neatitinka rezius [10;1000]. Iveskite tinkama skaiciu.\n");
                    return 1;
                }
            }
        }
    }
    return 1;
}

int CountNumbers(char number[]){
    int counter = 0;
    for(int i = 0; number[i] != '\0'; ++i){
        if(isdigit(number[i])){
            counter++;
        }
    }
    return counter;
}