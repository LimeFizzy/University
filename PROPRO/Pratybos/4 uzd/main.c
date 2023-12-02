//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 4
//Uzduoties variantas - 7

// Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo didžiausią elementą.

// TO-DO-HERE: pagrindinis failas (meniu, programos paleidimas, procedūrų iškvietimas)
#include <stdio.h>
#include "func.h"

#define WLC_MSG "Sveiki! Pasirinkite koki veiksma norite atlikti.\n"
#define MENU_1 "1 - Sukurti tuscia sarasa.\n"
#define MENU_2 "2 - Uzpilditi sarasa atsitiktinomis reiksmemis.\n"
#define MENU_3 "3 - Atspausdinti turima sarasa.\n"
#define MENU_4 "4 - Surasti sarase didziausia elementa ir ismesti ji.\n"
#define MENU_5 "5 - Istrinti sarasa.\n"
#define MENU_6 "6 - Iseiti is programos.\n"
#define CHOICE "Pasirinktas veiksmas: "
#define SUC_CH "Pasirinkimas sekmingai nuskaitytas.\n"
#define ERR_CH "Netinkama ivestis. Iveskite skaiciu 1-6 atitinkanti jusu norima veiksma.\n"
#define EMP_LIST "Tuscias sarasas sekmingai sukurtas.\n"
#define NO_FULL_LIST "Nera sukurta saraso. Sukurkite sarasa ir tik tada naudokite sia funkcija.\n"
#define LIST_QUESTION "Programoje jau yra sukurtas sarasas. Ar tikrai norite istustinti ji? [y/n]\n"
#define FULL_LIST_QUESTION "Programoje jau yra sukurtas sarasas. Ar tikrai norite pakeisti jo reiksmes? [y/n]\n"
#define ONE_MORE_TRY "Neteisinga ivestis, iseckite y - taip, arba n - ne.\n"
#define CONTINUE "Paspauskite ENTER, kad testi.\n"

// Funkcija atspausdinanti meniu pasirinkimus 
int menu(){
    int choice, validInput = 0;
    while(!validInput){
        printf("%s%s%s%s%s%s%s", MENU_1, MENU_2, MENU_3, MENU_4, MENU_5, MENU_6, CHOICE);
        if(scanf("%d", &choice) == 1 && (getchar()=='\n')){
            if(choice >= 1 && choice <= 6){
                printf("%s", SUC_CH);
                validInput = 1;
            }
            else{
                printf("%s", ERR_CH);
            }
        }
        else{
            printf("%s", ERR_CH);
            while(getchar() != '\n');
        }
    }
    printf("\n");
    return choice;
}


int main(){
    Node *start = NULL, *end = NULL;
    int maxValue = 0;
    int choice = 0;
    char option;
    printf("%s", WLC_MSG);
    while(1){
        choice = menu();
        switch (choice)
        {
        case 1:
            if(start == NULL){
                printf("%s", EMP_LIST);
            }
            else{
                printf("%s", LIST_QUESTION);
                while(1){
                    scanf("%c", &option);
                    if(Validation(option)){
                        start = NULL;
                        end = NULL;
                        break;
                    }
                    else if(Validation(option) == -1){
                        // Nieko nedarome
                        break;
                    }
                    else{
                        printf("%s", ONE_MORE_TRY);
                    }
                }
            }
            break;
        
        case 2:
            if(start == NULL){
                CreateList(&start, &end);
            }
            else{
                printf("%s", FULL_LIST_QUESTION);
                while(1){
                    scanf("%c", &option);
                    if(Validation(option)){
                        CreateList(&start, &end);
                        break;
                    }
                    else if(Validation(option) == -1){
                        // Nieko nedarome
                        break;
                    }
                    else{
                        printf("%s", ONE_MORE_TRY);
                    }
                }
            }
            break;
        
        case 3:
            if(start == NULL){
                printf("%s", NO_FULL_LIST);
            }
            else{
                PrintList(start);
                printf("\n");
            }
            break;

        case 4:
            if(start == NULL){
                printf("%s", NO_FULL_LIST);
            }
            else{
                maxValue = FindMaxValue(start);
                DeleteMaxValue(&start, maxValue);
            }
            break;

        case 5:
            start = NULL;
            end = NULL;
            break;

        case 6:
            return 0;
        
        default:
            break;
        }
        printf("%s", CONTINUE);
        while(getchar() != '\n');
    }
    return 0;
}