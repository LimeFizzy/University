#include <stdio.h>

int main(){
    int a, b, c;
    printf("Programa atspausdina visus teigiamus sveikus skaičius iš intervalo (a; b], kurie dalijasi iš skaičiaus c su liekana 1.\n");
    printf("Iveskite sveikuosius skacius a, b ir c: \n");
    scanf("%d %d %d", &a, &b, &c);
    printf("Ivestis sekmingai irasyta.\n");
    printf("Skaiciai, kurie dalijasi is %d su liekana 1: ", c);
    for(; a<=b; ++a){
        if(a%c==1){
            printf("%d ", a);
        }
    }
    return 0;
}