//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 2
//Uzduoties variantas - 1

//Įvesti sveiką skaičių N. Užpildyti matricą N*N sveikais skaičiais 1, 2, 3, ..., surašytais spirale. 

#include <stdio.h>
#include <math.h>

int main(){
    printf("Programa nuskaito viena sveikaji skaiciu N ir atspasdina skaicius nuo 1 iki N^2 matricoje uzpilditoje spirale.\n");
    int N, newnum=1, limit=0;
    printf("Iveskite svekaji skaiciu N\n");
    scanf("%d", &N);
    int numbers[N][N];
    while(1){
        int i=0, j=1;
        for(; i<N; ++i){
            numbers[i][j] = newnum;
            ++newnum;
            if(newnum == (N*N))
                break;
        }
        for(; j<N; ++j){
            numbers[i][j] = newnum;
            ++newnum;
            if(newnum == (N*N))
                break;
        }
        for(; i>0; --i){
            numbers[i][j] = newnum;
            ++newnum;
            if(newnum == (N*N))
                break;
        }
        for(; j > (0+limit); --j){
            numbers[i][j] = newnum;
            ++newnum;
            if(newnum == (N*N))
                break;
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            printf("%4d", numbers[i][j]);
        }
    }

    return 0;
}