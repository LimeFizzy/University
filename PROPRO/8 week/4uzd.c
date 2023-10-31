#include <stdio.h>
#include <stdlib.h>

int splitData(int array[], int arraySize, int split, int **first, int **second);

int main(){
    int *first = NULL, *second = NULL;
    int masyvas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int errorcode = splitData(masyvas, 10, 2, &first, &second);
    return 0;
}

int splitData(int array[], int arraySize, int split, int **first, int **second){
    if(first == NULL && second == NULL && arraySize >=0 && split <= arraySize && split >= 0){
        *first = (int *)malloc(split * sizeof(int));
        *second = (int *)malloc((arraySize - split) * sizeof(int));
        
        for(int i = 0; i < split; ++i){
            (*first)[i] = array[i];
            printf("%d ", first[i]);
        }

        for(int k = 0; split < arraySize; ++split, ++k){
            (*second)[k] = array[split];
        }
        return 0;
    }
    else{
        return -1;
    }
}
