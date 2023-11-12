#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aprasytos visi nauduojamieji pranesimai.
#define MAX_ARR 255
#define WelcomeMsg "Sveiki, sita programa randa ir atspausina visus zodzius, kuries vienodai skaitosi is pradzios ir is galo.\n"
#define AskForInput "Iveskite duomenu failo pavadinima. (pvz. duom.txt)\n"
#define AskForOutput "Iveskite rezultato failo pavadinima. (pvz. rez.txt)\n"
#define FileErrorMsg "Nepavyko atidaryti/surasti norimo failo.\n"
#define FileOpenSuccess "Failas sekmingai atidarytas!\n"
#define EndOfFile "Buvo pasiekta failo pabaiga.\n"
#define WrongFileInput "Neteisingas failo pavadinimas. Iveskite failo pavadinima formatu: \"filename.txt\".\n"
#define FileReadSuccess "Failo pavadinimas sekmingai nuskaitytas.\n"
#define OutputError "Nepavyko sukurti/atidaryti rezultatu failo.\n"
#define GoodByeMSG "Programa baige savo darba.\n"

// Procedura, kuri nustato ar vartotojo ivestis yra .txt failas ir issaugoja ji.
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
            printf("%s", WrongFileInput);
        }
        else if((fileName[pointLoc+1]=='t') && (fileName[pointLoc+2]=='x') && (fileName[pointLoc+3]=='t')){
            printf("%s", FileReadSuccess);
            validInput = 1;
        }
        else{
            printf("%s", WrongFileInput);
        }
    }
    
}

// Funkcija, kuri padalina nuskaityta teksto eilute i atskirus zodzius ir grazina dvimacio masyvo
// su tais zodziais adresa.
char** SeparateByWords(char *textLine, int *wordCounter){
    *wordCounter = 0;
    for(int i = 0; i < MAX_ARR; ++i){
        if(textLine[i] == ' '){
            (*wordCounter)++;
        }    
    }
    (*wordCounter)++;
    
    char **words = (char **)malloc(*wordCounter * sizeof(char*));
    for(int i = 0; i < *wordCounter; ++i){
        words[i] = (char *)malloc(MAX_ARR * sizeof(char));
    }

    for(int i = 0, j = 0, k = 0; i < MAX_ARR; ++i){
        if(textLine[i] != ' '){
            words[j][k] = textLine[i];
            ++k;
        }
        else if(textLine[i] == ' '){
            k = 0;
            j++;
        }
    }

    return words;
}

// Papildoma procedura atminties atlaisvinimui.
void freeMemory(char **words, int wordCount) {
    for (int i = 0; i < wordCount; ++i) {
        free(words[i]);
    }
    free(words);
}

// Procedura ieskanti palindromus ir isspausdina juos i rezultatu faila.
void FindPalindromes(char *input, char *output){
    int wordCounter = 0;
    int letterCounter = 0;
    int simillarityInd, realSimillarity=0;
    char line[MAX_ARR] = {0};
    char **onlyWords = NULL;
    
    FILE *data = fopen(input, "r");
    
    if(data == NULL){
        printf("%s", FileErrorMsg);
    }
    else{
        FILE *result = fopen(output, "w");
        if(result == NULL){
            printf("%s", OutputError);
            return;
        }

        printf("%s", FileOpenSuccess);
        
        while(fgets(line, MAX_ARR, data) != NULL){
            
            if(line[0] == '\n'){
                continue;
            }

            onlyWords = SeparateByWords(line, &wordCounter);

            for(int i = 0; i < wordCounter; ++i){
                for(int j = 0; onlyWords[i][j] != '\0'; ++j){
                    letterCounter++;
                }
                simillarityInd = letterCounter/2;

                for(int j = 0; j < simillarityInd; ++j){
                    if(onlyWords[i][j] == onlyWords[i][letterCounter-j-1]){
                        realSimillarity++;
                    }
                }
                
                if(realSimillarity == simillarityInd){
                    fprintf(result, "%s ", onlyWords[i]);
                }
                
                realSimillarity = 0;
                letterCounter = 0;
                memset(line, 0, MAX_ARR);
            }
            fprintf(result, "\n");
        }
        fclose(data);
        fclose(result);
        freeMemory(onlyWords, wordCounter);
        printf("%s", EndOfFile);
    }
}

int main(){
    char input[100] = {0}, output[100] = {0};
    printf("%s", WelcomeMsg);
    printf("%s", AskForInput);
    EnterFileName(input);
    printf("%s", AskForOutput);
    EnterFileName(output);
    FindPalindromes(input, output);
    printf("%s", GoodByeMSG);
    return 0;
}