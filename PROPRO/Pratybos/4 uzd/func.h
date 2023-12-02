#ifndef FILE_H
#define FILE_H
#include "func.c"
#include "unit.c"

void PrintList(Node *head);
int FindMaxValue(Node *head);
void DeleteMaxValue(Node **head, int num);
void CreateList(Node **start, Node **end);
int Validation(char x);

#endif