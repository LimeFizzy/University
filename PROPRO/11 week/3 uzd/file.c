#include <stdio.h>

int saveCount = 0;
int loadCount = 0;

void saveToFile(int array[], int capacity, char *filename){
    FILE *db = fopen(filename, "wb");
    if(db != NULL){
        fwrite(&capacity, sizeof(int), 1, db);
        for(int i = 0; i < capacity; ++i){
            fwrite(&array[i], sizeof(int), 1, db);
        }
        saveCount++;
    }
    fclose(db);
    
}

void loadFromFile(int array[], int *capacity, char *filename){
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
