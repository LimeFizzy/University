#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void generateArray(int data[], int size, int low, int high);

int main(){
    int array[MAX_SIZE];
    int size, low, high;
    scanf("%d %d %d", &size, &low, &high);
    generateArray(array, size, low, high);
    for(int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
    return 0;
}

void generateArray(int data[], int size, int low, int high){
    srand(time(NULL));
    if(low > high){
        exit(0);
    }
    for(int i = 0; i < size; ++i){
        data[i] = low + rand() % (high + 1 - low);
    }
}