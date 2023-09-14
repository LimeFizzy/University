#include <stdio.h>
#include <limits.h>

int main(){
    double sum = 0, counter = 0;
    int previousNum = INT_MIN, newNum, temp;
    
    while (1>0){
        printf("Iveskite sveikaji skaiciu.\n");
        if(scanf("%d", &temp)){
            newNum = temp;
            sum += temp;
            counter +=1;
            newNum = temp;
            if(newNum<previousNum) break;
            previousNum = temp;
        }
        else{
            printf("Neteisinga ivestis! Iveskite sveikaji skaiciu.\n");
            while(getchar() != '\n');
        }
    }
    //Output
    printf("Sekos nariu skaicius: %.0lf\n", counter);
    printf("Sekos nariu aritmetinis vidurkis: %.2lf\n", sum/counter);
    return 0;
}
