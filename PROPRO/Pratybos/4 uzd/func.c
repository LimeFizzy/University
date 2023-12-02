#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
typedef struct Node {
    int value;
    struct Node *next;
} Node;

void PrintList(Node *head){
    if(head != NULL){
        PrintList(head->next);
        printf("%d ", head->value);
    }
    printf("\n");
}

int FindMaxValue(Node *head){
    int max = INT_MIN;
    while(head != NULL){
        if(head->value > max){
            max = head->value;
        }
        head = head->next;
    }
    return max;
}   

void DeleteMaxValue(Node **head, int num){
    Node *current = *head;
    Node *prev = NULL;
    while(current != NULL){
        if(current->value == num){
            if(prev == NULL){
                *head = current->next;
                free(current);
                current = *head;
            } else{
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void CreateList(Node **start, Node **end){
    Node *tempNode;
    int value;
    int counter = 0;
    srand(time(NULL));
    *start = NULL;
    *end = NULL;
    while(counter < 10){
        value = 1 + rand() % 50;
        if(*start == NULL){
            tempNode = (Node *)malloc(sizeof(Node));
            tempNode->value = value;
            tempNode->next = NULL;
            *end = tempNode;
            *start = tempNode;
        } else {
            tempNode = (Node *)malloc(sizeof(Node));
            tempNode->value = value;
            tempNode->next = NULL;
            (*end)->next = tempNode;
            *end = tempNode;
        }
        counter++;
    }
}

int Validation(char x){
    if(x == 'n' || x == 'y'){
        if(x == 'y')
            return 1;
        else
            return -1;
    }
    return 0;
}