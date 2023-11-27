//LSP numeris - 2312091
//el. pastas - leonardas.sinkevicius@mif.stud.vu.lt
//Uzduoties numeris - 2
//Uzduoties variantas - 1

//Įvesti sveiką skaičių N. Užpildyti matricą N*N sveikais skaičiais 1, 2, 3, ..., surašytais spirale. 

#include <stdio.h>
#include <math.h>

int Validation(int x);
void FillMatrix(int n, int matrix[n][n]);
void Print(int n, int matrix[n][n]);

int main(){
    printf("Programa nuskaito viena teigiama sveikaji skaiciu N ir atspasdina skaicius nuo 1 iki N^2 matricoje uzpilditoje spirale.\n");
    int n = 0;
    //Validation
    n = Validation(n);
    int matrix[n][n];
    FillMatrix(n, matrix);
    Print(n, matrix);
    return 0;
}

int Validation(int x){
    while (1){
        printf("Iveskite sveikaji skaiciu.\n");
        if(scanf("%d", &x)== 1 && (getchar() == '\n')){
            if(x > 0){
                printf("Skaicius %d sekmingia nuskaitytas.\n", x);
            break;
            }
            else
                printf("Neteisinga ivestis! Iveskite teigiama sveikaji skaiciu.\n");
        }
        else{
            printf("Neteisinga ivestis! Iveskite teigiama sveikaji skaiciu.\n");
            while(getchar() != '\n');
        }
    }

    return x;
}


void FillMatrix(int n, int matrix[n][n]){
    int value = 1;
    int start_col_ind = 0, start_row_ind = 0;
    int final_col_ind = n, final_row_ind = n;
    
    while(start_col_ind < final_col_ind && start_row_ind < final_row_ind){
        //Fill the first row of the remaining
        for(int i = start_col_ind; i < final_col_ind; ++i){
            matrix[start_row_ind][i] = value++;
        }
        ++start_row_ind;
        //Fill the last column of the remaining
        for(int i = start_row_ind; i < final_row_ind; ++i){
            matrix[i][final_col_ind-1] = value++;
        }
        --final_col_ind;
        //Fill the last row of the remaining
        if(start_row_ind < final_row_ind){
            for(int i = final_col_ind-1; i >= start_col_ind; --i){
                matrix[final_row_ind-1][i] = value++;
            }
            --final_row_ind;
        }
        //Fill the first column of the remaining
        if(start_col_ind < final_col_ind){
            for(int i = final_row_ind-1; i >= start_row_ind; --i){
                matrix[i][start_col_ind] = value++;
            }
            ++start_col_ind;
        } 
    }
}

void Print(int n, int matrix[n][n]){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}