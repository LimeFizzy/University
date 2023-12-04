#include <stdio.h>
#include "file.h"

void saveToFile(int array[], int capacity, char *filename, int saveCount){
    FILE *db = fopen(filename, "wb");
    if(db != NULL){
        fwrite(&capacity, sizeof(int), 1, db);
        for(int i = 0; i < capacity; ++i){
            fwrite(&array[i], sizeof(int), 1, db);
        }
        saveCount++;
        printf("%d\n", saveCount);
    }
    fclose(db);
    
}

void loadFromFile(int array[], int *capacity, char *filename, int loadCount){
    FILE* db = fopen(filename, "rb");
    if(db != NULL){
        fread(capacity, sizeof(int), 1, db);
        for(int i = 0; i < *capacity; ++i){
            fread(&array[i], sizeof(int), 1, db);
        }
        loadCount++;
    }
    fclose(db);
}
