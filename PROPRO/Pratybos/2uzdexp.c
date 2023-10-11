#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** fill(int**, int);
void print(int**, int*);

int main() {
    int n, i;
    int **matrix = NULL;
    scanf("%d", &n); 
    matrix = malloc(n*sizeof(int*));                            /* pasiimam atminti pointeriams, kurie saugos adresus i kitus pointerius, saugancius adresus i kintamuosius*/
    for (i=0; i<n; i++) 
        matrix[i] = malloc(n*sizeof(int));
        /* *(matrix+i) = malloc(n*sizeof(int));                    kiekvienam pointeriui i kintamuosius isskiriam po n*4 baitu */
    fill(matrix, n);                                            /* uzpildom matrica spirales principu */
    print(matrix, &n);
    free(matrix); 
    return 0;
}

int** fill(int** matrix, int n) {
    int gg=1, x=0, y=0, maxim=n-1, squares=4*n-4, tmpgg=1;     /* maxim := indekso riba;     squares := 4 directionu ejimu skaicius */
    while (gg != n*n+1) {
        /**(*(matrix+x)+y) = gg;*/
        matrix[x][y] = gg;
        if (x < maxim && y == n-maxim-1)
            x++;
        else if (x == maxim && y < maxim)
            y++;
        else if (y == maxim && x <= maxim && x > n-maxim-1)
            x--;
        else if (x == n-maxim-1 && y <= maxim && y > n-maxim)
            y--;
        gg++;
        tmpgg++;
        if (tmpgg == squares) {
            tmpgg = 0;
            squares-=8;
            maxim--;
        }
    }
    return matrix;
}

void print(int** matrix, int *n) {
    int i, j;
    for (i=0; i<*n; i++) {
        for (j=0; j<*n; j++) {
            printf("%d ", matrix[j][i]);
            /*printf("%d ", *(*(matrix+j)+i));*/
        }
        printf("\n");
    }
}