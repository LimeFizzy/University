#include <stdio.h>

#define WelcomeMsg "Sveiki, sita programa randa ir atspausina visus zodzius, kuries vienodai skaitosi is pradzios ir is galo.\n"
#define AskForInput "Iveskite duomenu failo pavadinima. (pvz. duom.txt)\n"
#define AskForOutput "Iveskite rezultato failo pavadinima. (pvz. rez.txt)\n"
#define FileErrorMsg "Nepavyko atidaryti/surasti norimo failo.\n"
#define FileOpenSuccess "Failas sekmingai atidarytas!\n"

void EnterFileName(char *fileName){
    int validInput = 0;
    int pointLoc = -1;
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

/*void FindPalindromes(char *input, char *output){
    FILE *data = fopen(input, "r");
    if(data == NULL){
        printf("%s", FileErrorMsg);
    }
    else{                   // Pradzia darbo su teksto eilutemis
        printf("%s", FileOpenSuccess);
        char line[255] = {0};

    }

}*/

int main(){
    char input[] = {0}, output[] = {0};
    printf("%s", WelcomeMsg);
    printf("%s", AskForInput);
    EnterFileName(input);
    printf("%s", AskForOutput);
    EnterFileName(output);
    printf("Input - %s, output - %s", input, output);
    return 0;
}