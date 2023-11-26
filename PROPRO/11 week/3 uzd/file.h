#ifndef FILE_H
#define FILE_H
#include "file.c"

void saveToFile(int array[], int capacity, char *filename);
void loadFromFile(int array[], int *capacity, char *filename);

#endif 