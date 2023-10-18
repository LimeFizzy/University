#include <stdio.h>

int Validation(int x);
int Factorial(int n);

int main(){
    printf("Programa suskaiciuoja ivesto teigiamo skaiciaus faktoriala, isveda ji i ekrana ir atspausdina faile \"out.txt\"\n");
    int n = 0, temp;
    n = Validation(n);
    temp = n;
    printf("Skaiciaus %d faktorialas yra %d.\n", temp, Factorial(n));
    FILE* output = fopen("out.txt", "w");
    if(output == NULL){
        printf("Tekstinis failas nebuvo sukurtas.\n");
    }
    else
        printf("Failas su atsakymu buvo sekmingai sukurtas.\n");
    
    fprintf(output, "Skaiciaus %d faktorialas yra %d.\n", temp, Factorial(n));
    fclose(output);
    return 0;
}

int Validation(int x){
    while (1){
        printf("Iveskite viena teigiama skaiciu.\n");
        if(scanf("%d", &x)== 1 && (getchar() == '\n')){
            if(x > 0){
                printf("Skaicius %d sekmingia nuskaitytas.\n", x);
            break;
            }
            else
                printf("Neteisinga ivestis! Iveskite teigiama skaiciu.\n");
        }
        else{
            printf("Neteisinga ivestis! Iveskite teigiama skaiciu.\n");
            while(getchar() != '\n');
        }
    }

    return x;
}

int Factorial(int n){
    int k = n;
    n = 1;
    for(int i=1; i <= k; ++i){
        n *= i;
    }
    return n;
}