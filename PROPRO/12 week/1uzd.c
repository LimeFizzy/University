#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillArray(int array[], int capacity){
    srand(time(NULL));
    for(int i = 0; i < capacity; ++i){
        array[i] = 1 + rand()% 100;
    }
}

void check(int array[], int capacity){
    int count = 0;
    for(int i = 0; i < capacity-1; ++i){
        if(array[i] < array[i+1]){
            continue;
        }
        else{
            count++;
        }
    }
    if(count == 0){
        printf("All good\n");
    }
    else{
        printf("Something is wrong\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int capacity) {
    for (int i = 0; i < capacity - 1; i++) {
        for (int j = 0; j < capacity - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(){
    int test1[20];
    fillArray(test1, 20);
    bubbleSort(test1, 20);
    check(test1, 20);
    return 0;
}