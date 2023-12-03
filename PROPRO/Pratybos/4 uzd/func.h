#ifndef FILE_H
#define FILE_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void PrintList(Node *head);
int FindMaxValue(Node *head);
void DeleteMaxValue(Node **head, int num);
void CreateList(Node **start, Node **end);
void ReadList(Node **start, Node **end);
int Validation(char x);

#endif