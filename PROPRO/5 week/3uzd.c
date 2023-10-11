#include <stdio.h>

#define MAX_SIZE 1000

int main(){
    double s, array[MAX_SIZE];
    int n, counter = 1;
    
    printf("Programa nuskaito du skaicius s ir n. Po to nuskaitomi n teigiamu skaiciu. Kaip rezultatas isvedamos skaiciu poros kuriu sandauga duoda skaiciu s.\n");

    printf("Iveskite skaicius s ir n.\n");
    scanf("%lf %d", &s, &n);
    
    printf("Iveskite %d teigiamus skaiciu. Skaicius iveskite po viena.\n", n);
    for(int i=0; i<n; ++i){
        printf("Iveskite %d-aji teigiama skaiciu.\n", i+1);
        scanf("%lf", &array[i]);
        if(array[i] <= 0){
            printf("Neteisinga ivestis. Iveskite sveikaji skaiciu.\n");
            --i;
        }
        else
            printf("Skaicius sekmingai irasytas.\n");
    }
    
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            if((array[i]*array[j]) == s){
                printf("%d skaiciu pora - %.2lf ir %.2lf.\n", counter, array[i], array[j]);
                ++counter;
            }
        }
    }
    if(counter == 1)
        printf("Nera skaiciu poru kuriu sandauga butu lygi skaiciui s.\n");
    return 0;
}