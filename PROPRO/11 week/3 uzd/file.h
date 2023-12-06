#ifndef FILE_H
#define FILE_H

extern int saveCount;
extern int loadCount;

void saveToFile(int array[], int capacity, char *filename);
void loadFromFile(int array[], int *capacity, char *filename);

#endif 