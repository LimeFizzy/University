#include <stdio.h>
#include <ctype.h>

void Validation(char numbers[], double values[3]);

int main(){
    printf("Programa nuskaito 3 skaicius parasytus vienoje eiluteje, atskirtus kabliataskiais, ");
    printf("randa vidurini pagal reiksme skaiciu ir atspausdina ji tekstiniame faile, ");
    printf("kurio pavadinima iveda vartotojas.\n");
    printf("Iveskite 3 skaicius tokiu formatu: skaicius1;skaicius2;skaicius3\n");
    char numbers[] = {0};
    double values[3];
    Validation(numbers, values);
    return 0;
}

void Validation(char numbers[], double values[3]){
    double value;
    char temp[] = {0};
    int readSymbols = 0, counter = 1;    //counter of ';' symbols
    int breakPlaces[4] = {-1};
    scanf("%s", numbers);
    for(int i = 0; numbers[i] != '\0'; ++i){
        if(numbers[i] == ';'){
            breakPlaces[counter] = i;
            ++counter;
        }
        ++readSymbols;
    }
    if(counter !=3){
        printf("Neteisinga ivestis. Iveskite 3 skaicius tokiu formatu: skaicius1;skaicius2;skaicius3\n");
    }
    else if(!(isdigit(numbers[breakPlaces[2]+1]))){
        printf("Neteisinga ivestis. Iveskite 3 skaicius tokiu formatu: skaicius1;skaicius2;skaicius3\n");
    }
    else{
        breakPlaces[3] = readSymbols;
        for(int i=0; i<3; ++i){
            for(int j=breakPlaces[i]+1, k=0; j<breakPlaces[i+1]; ++j, ++k){
                temp[k] = numbers[j];
                printf("%c", temp[k]);
            }
            char temp[]={0};
            sscanf(temp, "%lf", &value);
            
            printf(" ");
            values[i] = value;
            //printf("%lf ", value);
        }
        //printf("Ivestis sekmingai irasyta.\n");
    }
}