#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size);

int main(){
    int s;
    scanf("%d", &s);
    printf("%p", createArray(s));
    return 0;
}

int *createArray(int size){
    int low = 0, high = 10;
    int *array = malloc(size * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        *(array+i) = low + rand() % (high + 1 - low);
    }
    return array;
}