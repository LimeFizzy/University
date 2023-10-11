#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main(){
    int masyvas[MAX_SIZE];
    int a, b, c;
    printf("Gavus is naudotojo tris skaicius a, b ir c, programa i masyva irasys c atsitiktinai sugeneruotu reiksmiu, kiekviena is kuriu priklauso intervalui [a; b], ir atspausdins masyvo turini (tas c reiksmiu) i ekrana.\n");
    
    printf("Iveskite skaicius a, b ir c. Skaicius a turi buti mazesnis uz b.\n");
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a<b){
            printf("Ivestis nuskaityta sekmingai.\n");
            break;
        }
        else
            printf("Neteisinga ivestis. Iveskite skaicius a, b ir c. Skaicius a turi buti mazesnis uz b.");
    }
    
    srand(time(NULL));
    for(int i=0; i<c; ++i){
        masyvas[i] = a + rand() % (b-a+1);
    }
    
    for(int i=0; i<c; ++i)
        printf("%d ", masyvas[i]);

    return 0;
}