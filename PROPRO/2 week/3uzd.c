#include <stdio.h>

int main(){
    int number;
    if(scanf("%d", &number)==1 && getchar()=='\n'){
        printf(0==number%2 ? "%s", "Skaicius yra teigiamas\n": "%s", "Skaicius yra neigiamas\n");
    }
    else printf("Tai ne sveikasis skaicius.");
    return 0;
}