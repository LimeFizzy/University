//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 2
//Uzduoties variantas - 1

//Įvesti sveiką skaičių N. Užpildyti matricą N*N sveikais skaičiais 1, 2, 3, ..., surašytais spirale. 

#include <stdio.h>
#include <math.h>



int main(){
    int N;
    scanf("%d", &N);
    int numbers[N*N];
    for(int i=1; i<=pow(N, 2); i++) {
        numbers[i-1]=i;
        printf("%d ", numbers[i-1]);
    }
    return 0;
}