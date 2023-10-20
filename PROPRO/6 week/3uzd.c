#include <stdio.h>
#include <ctype.h>

void Validation(double *values);
int FindMid(double *values);
void EnterFileName(char *fileName);

int main(){
    printf("Programa nuskaito 3 skaicius parasytus vienoje eiluteje, atskirtus kabliataskiais, ");
    printf("randa vidurini pagal reiksme skaiciu ir atspausdina ji tekstiniame faile, ");
    printf("kurio pavadinima iveda vartotojas.\n");
    printf("Iveskite 3 skaicius tokiu formatu: skaicius1;skaicius2;skaicius3\n");
    double values[3];
    char fileName[] = {0};
    Validation(values);
    double midValue = values[FindMid(values)];
    EnterFileName(fileName);
    FILE* result = fopen(fileName, "w");
    if(result == NULL){
        printf("Tekstinis failas nebuvo sukurtas.\n");
    }
    else
        printf("Failas su atsakymu buvo sekmingai sukurtas.\n");
    fprintf(result, "Ivestu skaiciu vidurine reiksme yra %.2lf", midValue);
    fclose(result);
    return 0;
}

void Validation(double *values){
    int validInput = 0;
    while(validInput != 1){
        if((scanf("%lf;%lf;%lf", &values[0], &values[1], &values[2])==3) && getchar()=='\n'){
            printf("Ivestis sekmingai nuskaityta!\n");
            validInput = 1;
        }
        else{
            printf("Klaidinga ivestis. Iveskite 3 skaicius tokiu formatu: skaicius1;skaicius2;skaicius3\n");
            while(getchar() != '\n');
        }
    }
}

int FindMid(double *values){
    int max = values[0] < values[1] ? 1 : 0;
    max = values[max] < values[2] ? 2 : max;

    int min = values[0] < values[1] ? 0 : 1;
    min = values[min] < values[2] ? min : 2;
    int mid;
    for(int i = 0; i < 3; ++i){
        if((max != i) && (min != i))
            mid = i;
    }
    return mid;
}

void EnterFileName(char *fileName){
    int validInput = 0;
    int pointLoc = -1;
    printf("Iveskite tekstinio failo i kuri norite issaugoti rezultata pavadinima. Pvz.: rez.txt\n");
    while(validInput != 1){
        
        scanf("%s", fileName);
        for(int i=0; fileName[i] != '\0'; ++i){
            if(fileName[i] == '.'){
                pointLoc = i;
            }
        }

        if(pointLoc == -1 || pointLoc == 0){
            printf("Neteisingas failo pavadinimas. Iveskite failo pavadinima formatu: \"filename.txt\".\n");
        }
        else if((fileName[pointLoc+1]=='t') && (fileName[pointLoc+2]=='x') && (fileName[pointLoc+3]=='t')){
            printf("Failo pavadinimas sekmingai nuskaitytas.\n");
            validInput = 1;
        }
        else{
            printf("Neteisingas failo pavadinimas. Iveskite failo pavadinima formatu: \"filename.txt\".\n");
        }
    }
}
