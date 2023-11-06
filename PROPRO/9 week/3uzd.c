#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;

typedef struct Stack
{
    Point *array;
    int capacity;
}Stack;

void initStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
double getDistance(Point a);
void printStack(Stack *stack);

int main(){
    Stack s1;
    Point p1 = {1 , 4}, p2 = {0 , 3}, p3 = {3, 5}, p4 = {2, 0}, p5 = {1, 9};
    initStack(&s1);
    push(&s1, p1);
    push(&s1, p2);
    push(&s1, p3);
    push(&s1, p4);
    push(&s1, p5);
    printStack(&s1);
    return 0;
}

void initStack(Stack *stack){
    stack->array = NULL;
    stack->capacity = 0;
}

int getStackSize(Stack *stack){
    return stack->capacity;
}

void push(Stack *stack, Point value){
    stack->capacity++;
    stack->array = (Point *)realloc(stack->array, (stack->capacity)*sizeof(Point));
    stack->array[stack->capacity-1] = value;
}

Point top(Stack *stack){
    if(stack->capacity == 0){
        Point p0 = {0};
        return p0;
    }
    else{
        Point p1 = stack->array[stack->capacity-1];
        return p1;
    }
}

Point pop(Stack *stack){
    stack->capacity--;
    stack->array = (Point *)realloc(stack->array, stack->capacity * sizeof(Point));
    return top(stack);
}

double getDistance(Point a){
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

void printStack(Stack *stack){
    for(int i = 0; i < stack->capacity; ++i){
        printf("(%.1lf,%.1lf)\n", stack->array[i].x, stack->array[i].y);
        printf("Distance - %.2lf\n", getDistance(stack->array[i]));
    }
    printf("\n");
}