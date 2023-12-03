#ifndef FUNC_H
#define FUNC_H

typedef struct Node Node;

void PrintList(Node *head);
int FindMaxValue(Node *head);
void DeleteMaxValue(Node **head, int num);
void CreateList(Node **start, Node **end);
void ReadList(Node **start, Node **end);
int Validation(char x);

#endif