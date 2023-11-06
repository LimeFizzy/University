#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *array;             // dinaminio masyvo rodykle
    int capacity;           // masyvo talpa
}Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main(){
    Stack s1;
    initStack(&s1);
    push(&s1, 1);
    printStack(&s1);
    push(&s1, 2);
    printStack(&s1);
    push(&s1, 3);
    printStack(&s1);
    printf("%d\n", pop(&s1));
    destroyStack(&s1);
    printStack(&s1);
    return 0;
}

void initStack(Stack *stack){
    stack->array = NULL;
    stack->capacity = 0;
}

void printStack(Stack *stack){
    for(int i = 0; i < stack->capacity; ++i){
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack){
    return stack->capacity;
}

void push(Stack *stack, int value){
    stack->capacity++;
    stack->array = (int *)realloc(stack->array, (stack->capacity)*sizeof(int));
    stack->array[stack->capacity-1] = value;
}

int top(Stack *stack){
    if(stack->capacity == 0){
        return 0;
    }
    else{
        return stack->array[stack->capacity-1];
    }
}

int pop(Stack *stack){
    stack->capacity--;
    stack->array = (int *)realloc(stack->array, stack->capacity * sizeof(int));
    return top(stack);
}

void destroyStack(Stack *stack){
    free(stack->array);
    stack->capacity = 0;
}