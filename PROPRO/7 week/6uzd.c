#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main(){
    char title[] = "Pasirinkite veiksma kuri norite atlikti.\n";
    char *options[] = {"1 - Paleisti programa is naujo.\n", "2 - Issaugoti programa.\n", "3 - Iseiti is programos.\n"};
    int size = 3;
    char input[] = "Pasirinkite norima veiksma. Iveskite skaiciu nuo 1 iki ";
    int userInput = showMenu(title, options, size, input);
    printf("%d\n", userInput);
    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    int validInput = 0;
    int userInput;
    while(validInput != 1){
        printf("%s", menuTitle);
        for(int i = 0; i < menuSize; ++i){
            printf("%s", menuOptions[i]);
        }
        printf("%s%d: ", inputMsg, menuSize);
        if(scanf("%d", &userInput) == 1 && getchar() == '\n'){
            if(userInput < 1 || userInput > menuSize){
                continue;
            }
            printf("Veiksmas sekmingai pasirinktas.\n");
            validInput = 1;
        }
        else{
            while(getchar() != '\n');
        }
    }
    return userInput;
}