#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 255
#define WelcomeMsg "Sveiki, sita programa randa ir atspausina visus zodzius, kuries vienodai skaitosi is pradzios ir is galo.\n"
#define AskForInput "Iveskite duomenu failo pavadinima. (pvz. duom.txt)\n"
#define AskForOutput "Iveskite rezultato failo pavadinima. (pvz. rez.txt)\n"
#define FileErrorMsg "Nepavyko atidaryti/surasti norimo failo.\n"
#define FileOpenSuccess "Failas sekmingai atidarytas!\n"
#define EndOfFile "Buvo pasiekta failo pabaiga.\n"

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

char** SeparateByWords(char *textLine, int *wordCounter){
    *wordCounter = 0;
    for(int i = 0; i < MAX_ARR; ++i){
        if(textLine[i] == ' '){
            (*wordCounter)++;
        }    
    }
    (*wordCounter)++;
    
    // Allocating 2D array for words in line
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


void FindPalindromes(char *input){
    FILE *data = fopen(input, "r");
    int wordCounter = 0;
    int letterCounter = 0;
    int simillarityInd, realSimillarity=0;
    char line[MAX_ARR] = {0};
    char **onlyWords = NULL;
    if(data == NULL){
        printf("%s", FileErrorMsg);
    }
    else{
        printf("%s", FileOpenSuccess);
        while(!(feof(data))){
            fgets(line, MAX_ARR, data);
            onlyWords = SeparateByWords(line, &wordCounter);
            for(int i = 0; i < wordCounter; ++i){
                //printf("%s - ", onlyWords[i]);
                for(int j = 0; onlyWords[i][j] != NULL; ++j){
                    letterCounter++;
                }
                simillarityInd = letterCounter/2;
                //printf("%d - %d\n",letterCounter, simillarityInd);

                for(int j = 0; j < simillarityInd; ++j){
                        if(onlyWords[i][j] == onlyWords[i][letterCounter-j-1]){
                            realSimillarity++;
                            //printf("%d", realSimillarity);
                        }
                }

                if(realSimillarity == simillarityInd){
                    printf("%s ", onlyWords[i]);
                }
                realSimillarity = 0;
                letterCounter = 0;
            }

        }

        printf("\n%s", EndOfFile);
    }

}


int main(){
    char input[100] = "data.txt", output[100] = "rez.txt";
    /*printf("%s", WelcomeMsg);
    printf("%s", AskForInput);
    EnterFileName(input);
    printf("%s", AskForOutput);
    EnterFileName(output);
    */
    FindPalindromes(input);
    return 0;
}