#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"
#ifndef stack_h
#define stack_h


struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *q, int s)
{
    q->top = -1;
    q->size = s;
    q->S = (struct Node **)malloc(sizeof(struct Stack *));
}

int isStackEmpty(struct Stack *q)
{
    return q->top == -1? 1 : 0;
}

int isStackFull(struct Stack *q)
{
    return (q->top == q->size - 1)? 1 : 0;
}

void push(struct Stack *q, struct Node *x)
{
    if( isStackFull(q) )
        printf("\nStack Overflow\n");
    else
    {
        q->top++;
        q->S[q->top] = x; 
    }
}

struct Node *pop(struct Stack *q)
{
    struct Node *x = NULL;
    if( isStackEmpty(q) )
        printf("\nStack Underflow\n");
    else
        x = q->S[q->top--]; 
    return x;
}

#endif