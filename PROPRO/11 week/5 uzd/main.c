#include "file.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR 20

void fillArray(int array[], int capacity){
    srand(time(NULL));
    for(int i = 0; i < capacity; ++i){
        array[i] = 1 + rand()% 100;
    }
}

void printArray(int array[], int capacity){
    for(int i = 0; i < capacity; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    int *m1 = NULL, *m2 = NULL, *m3 = NULL;
    int cap;
    m1 = (int *)malloc(MAX_ARR * sizeof(int));
    m2 = (int *)malloc(MAX_ARR * sizeof(int));
    m3 = (int *)malloc(MAX_ARR * sizeof(int));
    
    fillArray(m1, MAX_ARR);
    fillArray(m2, MAX_ARR);
    fillArray(m3, MAX_ARR);

    saveToFile(m1, MAX_ARR, "db1.bin");
    saveToFile(m3, MAX_ARR, "db1.bin");
    
    loadFromFile(m1, &cap, "db1.bin");
    
    saveToFile(m2, MAX_ARR, "db2.bin");
    loadFromFile(m3, &cap, "db2.bin");
    loadFromFile(m2, &cap, "db1.bin");
    
    if(saveCount == 3 && loadCount == 3){
        printf("all good\n");
    }
    else{
        printf("something's wrong\n");
    }

    free(m1);
    free(m2);
    free(m3);

    return 0;
}