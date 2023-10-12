//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 2
//Uzduoties variantas - 1

//Įvesti sveiką skaičių N. Užpildyti matricą N*N sveikais skaičiais 1, 2, 3, ..., surašytais spirale. 

#include <stdio.h>
#include <math.h>

void FillSpiral(int n, int numbers[n][n]);

int main(){
    printf("Programa nuskaito viena teigiama sveikaji skaiciu N ir atspasdina skaicius nuo 1 iki N^2 matricoje uzpilditoje spirale.\n");
    int n;
    //Validation
    while (1){
        printf("Iveskite sveikaji skaiciu.\n");
        if(scanf("%d", &n)== 1 && (getchar() == '\n')){
            if(n > 0){
                printf("Skaicius %d sekmingia nuskaitytas.\n", n);
            break;
            }
            else
                printf("Neteisinga ivestis! Iveskite teigiama sveikaji skaiciu.\n");
        }
        else{
            printf("Neteisinga ivestis! Iveskite teigiama sveikaji skaiciu.\n");
        }
    }
    int numbers[n][n];
    FillSpiral(n, numbers);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%4d", numbers[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void FillSpiral(int n, int numbers[n][n]){
    int value = 1;
    int start_col_ind = 0, start_row_ind = 0;
    int final_col_ind = n, final_row_ind = n;
    
    while(start_col_ind < final_col_ind && start_row_ind < final_row_ind){
        //Fill the first row of the remaining
        for(int i = start_col_ind; i < final_col_ind; ++i){
            numbers[start_row_ind][i] = value++;
        }
        ++start_row_ind;
        //Fill the last column of the remaining
        for(int i = start_row_ind; i < final_row_ind; ++i){
            numbers[i][final_col_ind-1] = value++;
        }
        --final_col_ind;
        //Fill the last row of the remaining
        if(start_row_ind < final_row_ind){
            for(int i = final_col_ind-1; i >= start_col_ind; --i){
                numbers[final_row_ind-1][i] = value++;
            }
            --final_row_ind;
        }
        //Fill the first column of the remaining
        if(start_col_ind < final_col_ind){
            for(int i = final_row_ind-1; i >= start_row_ind; --i){
                numbers[i][start_col_ind] = value++;
            }
            ++start_col_ind;
        } 
    }
}