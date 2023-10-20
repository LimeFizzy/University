#include <stdio.h>
#include <stdlib.h>

void Validation(int *year, int *month, int *day);
int ConvertToWeekday(int year, int month, int day);
void FillWeekdaysArray(char days[][15]);

int main(){
    printf("Programa nuskaito data (nuo 1700 iki 2399 metu) ir kaip rezultata grazina kokia tai savaites diena.\n");
    int year = 0 , month = 0, day = 0;
    Validation(&year, &month, &day);
    char days[7][15];
    FillWeekdaysArray(days);
    printf("Jusu ivesta data %d-%d-%d, tai %s.\n", year, month, day, days[ConvertToWeekday(year, month, day)]);
    return 0;
}

void Validation(int *year, int *month, int *day){
    int validInput = 0;
    printf("Iveskite data YYYY-MM-DD formatu. ");
    while(validInput != 1){
        if((scanf("%d-%d-%d", year, month, day)==3) && getchar()=='\n'){
            if((*year > 1699) && (*year < 2400) && (*month > 0) && (*month < 13) && (*day > 0) && (*day < 32)){
                printf("Data sekmingai nuskaityta!\n");
                validInput = 1;
            }
            else{
                printf("Klaidinga ivestis. Iveskite data tokiu formatu: YYYY-MM-DD. (nuo 1700 iki 2399 metu)\n");
                while(getchar() != '\n');
            }
        }
        else{
            printf("Klaidinga ivestis. Iveskite data tokiu formatu: YYYY-MM-DD. (nuo 1700 iki 2399 metu)\n");
            while(getchar() != '\n');
        }
    }
}

int ConvertToWeekday(int year, int month, int day){
    int yearCode = (year%100+(year%100/4))%7;
    int monthCodes[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int monthCode = monthCodes[month-1];
    int centuryCodes[7] = {4, 2, 0, 6, 4, 2, 0};
    int centuryCode = centuryCodes[year/100-17];
    
    int leapYearCode;
    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)){
        leapYearCode = 1;
    }
    else
        leapYearCode = 0;
    int weekday = (yearCode + monthCode + centuryCode + day - leapYearCode)%7;
    return weekday;
}

void FillWeekdaysArray(char days[][15]){
    FILE* weekdays = fopen("week.txt", "r");
    for(int i=0; i<7; ++i){
        fscanf(weekdays, "%s", days[i]);
    }
    fclose(weekdays);
}
