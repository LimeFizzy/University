#ifndef FILE_H
#define FILE_H

void saveToFile(int array[], int capacity, char *filename, int *saveCount);
void loadFromFile(int array[], int *capacity, char *filename, int *loadCount);

#endif 