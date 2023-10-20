#include <stdio.h>
#include <stdlib.h>

int ValidateEmail(char email[]);
void SaveDomain(char domain[], char email[],int atSignLoc);
void PrintDomain(char domain[]);

int main(){
    printf("Programa nuskaito el. pastus ir uzraso tinkamus domenus.\n");
    char email[100] = {0}, domain[95] = {0};
    int atSignLoc = ValidateEmail(email);
    SaveDomain(domain, email, atSignLoc);
    PrintDomain(domain);
    return 0;
}

int ValidateEmail(char email[]){
    printf("Iveskite el. pasta, pvz: vardenis@gmail.com\n");
    int atSignLoc = -1, dotAfterAt = -1, charCount = 0;
    int validInput = 0;
    while(validInput != 1){
        if((scanf("%s", email) == 1) && (getchar() == '\n')){
            for(int i = 0; email[i] != '\0'; ++i){
                if(email[i] == '@'){
                    atSignLoc = i;
                    validInput = 1;
                }
                ++charCount;
            }
            for(int i = atSignLoc; i < charCount; ++i){
                if(email[i] == '.'){
                    dotAfterAt = i;
                    validInput = 1;
                }
            }
            if(atSignLoc == -1 || dotAfterAt == -1){
                printf("Neteisinga ivestis. Ivestis neatitinka reikiamo formato.\n");
                validInput = 0;
            }
            if(atSignLoc == 0){
                printf("Neteisinga ivesti. Pries @ zenkla turi buti bent 1 simbolis.\n");
                validInput = 0;
            }
            else if(dotAfterAt+1 == charCount){
                printf("Neteisinga ivesti. Po paskutinio tasko privalo buti bent 1 simbolis.\n");
                validInput = 0;
            }
            else if(dotAfterAt == atSignLoc+1){
                printf("Neteisinga ivesti. Tarp @ zenklo ir paskutinio tasko privalo buti bent 1 simbolis.\n");
                validInput = 0;
            }

            if(validInput == 1){
                printf("Ivestis sekmingai nuskaityta.\n");
            }
        }
        else{
            printf("Neteisinga ivestis. Iveskite el. pasta, pvz: vardenis@gmail.com\n");
            while(getchar() != '\n');
        }
    }
    return atSignLoc;
}

void SaveDomain(char domain[], char email[], int atSignLoc){
    for(int i = atSignLoc+1, k=0; email[i] != '\0'; ++i, ++k){
        domain[k] = email[i];
    }
}

void PrintDomain(char domain[]){
    FILE* allDomains = fopen("emails.txt", "a");
    fputs(domain, allDomains);
    fclose(allDomains);
}