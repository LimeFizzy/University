#include <stdio.h>

int getPositiveNumber(char *msg);

int main(){
    char msg[] = "Iveskite viena sveikaji skaiciu.\n";
    int num = getPositiveNumber(msg);
    printf("%d", num);
    return 0;
}

int getPositiveNumber(char *msg){
    int validInput = 0, number;
    while(validInput != 1){
        printf("%s", msg);
        if(scanf("%d", &number) == 1 && getchar() == '\n'){
            printf("Skaicius sekmingai nuskaitytas.\n");
            validInput = 1;
        }
        else{
            while(getchar() != '\n');
        }
    }
    return number;
}