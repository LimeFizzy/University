//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 4
//Uzduoties variantas - 7

// Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo didžiausią elementą.

// TO-DO-HERE: pagrindinis failas (meniu, programos paleidimas, procedūrų iškvietimas)

// Turi būti sukurtas paprastas vartotojo meniu. Čia tik pavyzdys ir jį galima laisvai keisti pagal savo poreikius.:
// Pastaba: apgalvoti įvairius atvejus
// jei kelis kartus spaudžiama tas pats mygtukas (pvz. 2 kartus nuskaito iš duomenų failo). 
// galbūt įspėti prieš kritinus veiksmus. Pvz. jei jau turime sąrašą atmintyje ir norime sukurti tuščią sąrašą (šiuo atveju spaudžiame 0). Vartotojas turi būti įspėtas, kad dabar esančio sąrašo duomenys dings ir patvirtinti arba atšaukti pasirinkimą  
// ir panašūs atvejai
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
    printf("%d", choice);
    
    return choice;
}


int main(){
    int choice = 0;
    printf("%s", WLC_MSG);
    while(choice != 6){
        choice = menu();
    }

    Node *start, *end;
    int maxValue = 0;
    CreateList(&start, &end);
    printf("Generated list out of 10 elements:\n");
    PrintList(start);
    maxValue = FindMaxValue(start);
    printf("\nMax value is: %d\n", maxValue);
    DeleteMaxValue(&start, maxValue);
    PrintList(start);
    return 0;
}