#include <stdio.h>

int main(){
    int c;
    int FibonaciNum[100]={0};
    printf("Programa isveda c-ati fibonaci sekos skaiciu.\n");
    printf("Iveskite 3 neneigiamus sveikuosius skaicius a, b ir c.\n");
    scanf("%d %d %d", &FibonaciNum[0], &FibonaciNum[1], &c);
    printf("Ivestis sekmingai irasyta.\n");
    for(int i=0; i+2<=c; ++i){
        FibonaciNum[i+2]=FibonaciNum[i]+FibonaciNum[i+1];
    }
    printf("%d-asis fibonaci sekos skaicius yra %d.\n", c, FibonaciNum[c]);
    return 0;
}