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
    int *m1 = NULL, *m2 = NULL;
    m1 = malloc(MAX_ARR * sizeof(int));
    m2 = malloc(MAX_ARR * sizeof(int));
    int cap;
    fillArray(m1, MAX_ARR);
    printArray(m1, MAX_ARR);
    saveToFile(m1, MAX_ARR);
    loadFromFile(m2, &cap);
    printArray(m2, cap);
    if(strcmp((char *)m1, (char *)m2) == 0){
        printf("all good\n");
    }
    else{
        printf("something's wrong\n");
    }
    return 0;
}