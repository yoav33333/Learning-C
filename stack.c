#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int maxSize;
    int *arr;
    int top;
    void (*push)(struct stack *stack, int data);
    int (*pop)(struct stack *stack);
    int (*peek)(struct stack *stack);
    int (*isEmpty)(struct stack *stack);
    int (*isFull)(struct stack *stack);
    void (*Free)(struct stack *stack);
}stack;

void setSize(stack *stack, int size){
    stack->maxSize = size;
    stack->top = -1;
    stack->arr = (int *)malloc(size * sizeof(int));
}

int isEmpty(stack *stack){
    return stack->top==-1 ? 1 : 0;
}

int isFull(stack *stack){
    return stack->top>=stack->maxSize-1 ? 1 : 0;
}

void push(stack *stack, int data) {
    if (stack->isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++(stack->top)] = data;
}

int pop(stack *stack) {
    if (stack->isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}


int peek(stack *stack) {
    if (stack->isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top[stack->arr];
}

void Free(stack *stack){
    free(stack->arr);
}

void initStack(stack *stack){
    stack->isEmpty = isEmpty;
    stack->isFull = isFull;
    stack->push = push;
    stack->pop = pop;
    stack->peek = peek;
    stack->Free = Free;
}


