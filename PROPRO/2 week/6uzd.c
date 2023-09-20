#include <stdio.h>

int main(){
    int x=0, y=0, z=0;
    while(1>0){
        printf("Iveskite kintamojo x reiksme: ");
        if((scanf("%d", &x)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis\n");
            while(getchar() != '\n');
        }
    }

    printf("%d", x);
    return 0;
}