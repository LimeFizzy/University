//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 1
//Uzduoties variantas - 1

#include <stdio.h>
#include <limits.h>

int main(){
    double sum = 0, counter = 0;
    int previousNum = INT_MIN, newNum;
    
    while (1>0){
        printf("Iveskite sveikaji skaiciu.\n");
        if(scanf("%d", &newNum)){
            sum += newNum;
            counter ++;
            if(newNum<previousNum) break;
            previousNum = newNum;
        }
        else{
            printf("Neteisinga ivestis!\n");
            while(getchar() != '\n');
        }
    }
    printf("Sekos nariu skaicius: %.0lf\n", counter);
    printf("Sekos nariu aritmetinis vidurkis: %.2lf\n", sum/counter);
    return 0;
}
