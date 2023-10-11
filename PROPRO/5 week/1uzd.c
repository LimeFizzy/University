#include <stdio.h>

int main(){
    //a)
    int masyvas[10] = {0};
    //b)
    for(int i=0; i<10; ++i)
        printf("%d ", masyvas[i]);
    printf("\n");
    //c)
    masyvas[0] = 1;
    masyvas[3] = 2;
    masyvas[9] = 3;
    //d)
    for(int i=3; i<9; ++i)
        masyvas[i] = masyvas[i+1];
    masyvas[9] = 0;
    //e)
    for(int i=9; i>6; --i)
        masyvas[i] = masyvas[i-1];
    masyvas[6] = 4;
    //f)
    for(int i=0; i<10; ++i)
        printf("%d ", masyvas[i]);
    //g)
    printf("\nIveskite 2 sveikuosius skaicius X ir Y. (X reziai [0;9]). Programa masyvo elementui su indeksu X priduos reiksme Y.\n");
    int X, Y;
    scanf("%d %d", &X, &Y);
    printf("Skaiciai X=%d ir Y=%d sekmingai nuskaityti.\n", X, Y);
    masyvas[X] = Y;
    //h)
    printf("Iveskite skaciu X(reziai [0;9]). Programa istrins skaiciu su indeksu X is masyvo.\n");
    while(1){
        scanf("%d", &X);
        if(X<0 || X>9)
            printf("Neteisinga ivestis. Iveskite skaciu X atitinkanti rezius [0:9].\n");
        else{
            printf("Skaicius X=%d sekmingai nuskaitytas.\n", X);
            break;
        }  
    }
    for(int i=X; i<9; ++i)
        masyvas[i] = masyvas[i+1];
    masyvas[9] = 0;
    //i)
    printf("Iveskite 2 sveikuosius skaicius X ir Y. (X reziai [0;9]). Programa iterps skaiciu Y i masyva taip, kad po oterpimo jo indeksas butu X.\n");
    while(1){
        scanf("%d %d", &X, &Y);
        if(X<0 || X>9)
            printf("Neteisinga ivestis. Iveskite 2 sveikuosius skaicius X ir Y. (X reziai [0;9])\n");
        else{
            printf("Skaiciai X=%d ir Y=%d sekmingai nuskaityti.\n", X, Y);
            break;
        }  
    }
    for(int i=9; i > (X-1); --i)
        masyvas[i] = masyvas[i-1];
    masyvas[X] = Y;
    //j)
    for(int i=0; i<10; ++i)
        printf("%d ", masyvas[i]);
    return 0;
}