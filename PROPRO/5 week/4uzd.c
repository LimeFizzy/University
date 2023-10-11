#include <stdio.h>

#define MAX_SIZE 1000

int main(){
    int numbers[MAX_SIZE];
    int counter = 0, count_pirm = 0;
    printf("Programa nuskaito teigiamus skaicius ir isveda visus pirminius skaicius ivestoje sekoje.\n");
    while(1){
        printf("Iveskite %d-aji tegiama skaiciu.\n", counter+1);
        scanf("%d", &numbers[counter]);
        if(numbers[counter] > 0){
            printf("Ivestis sekmingai irasyta.\n");
            ++counter;
        }
        else{
            printf("Sekos nuskaitymas baigtas.\n");
            break;
        }
    }

    printf("Ivestos sekos pirminiai skaiciai: ");
    for(int i = 0; i<counter; ++i){
        for(int j = 1; j <= numbers[i]; ++j){
            if(numbers[i]%j == 0) 
                ++count_pirm;
        }
        if(count_pirm==2)
            printf("%d ", numbers[i]);
        count_pirm = 0;
    }
    return 0;
}