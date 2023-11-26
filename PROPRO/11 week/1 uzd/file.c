#include <stdio.h>
//#include "file.h"

void saveToFile(int array[], int capacity){
    FILE *db = fopen("db.bin", "wb");
    if(db != NULL){
        fwrite(&capacity, sizeof(int), 1, db);
        for(int i = 0; i < capacity; ++i){
            fwrite(&array[i], sizeof(int), 1, db);
        }
    }
    fclose(db);
}

void loadFromFile(int array[], int *capacity){
    FILE* db = fopen("db.bin", "rb");
    if(db != NULL){
        fread(capacity, sizeof(int), 1, db);
        for(int i = 0; i < *capacity; ++i){
            fread(&array[i], sizeof(int), 1, db);
        }
    }
    fclose(db);
}
