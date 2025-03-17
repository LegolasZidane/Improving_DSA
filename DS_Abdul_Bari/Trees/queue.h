#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int front;
    int rear;
    int size;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->Q = (struct Node **)malloc((q->size)*sizeof(struct Node *));
    q->front = q->rear = 0;//Important
}

int isQueueEmpty(struct Queue q)
{
    if( q.front == q.rear )
        return 1;
    else
        return 0;
}

int isQueueFull(struct Queue q)
{
    if( (q.rear + 1)%q.size == q.front )
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, struct Node *data)
{
    if( isQueueFull(*q) )
        printf("\nQueue Overflow\n");
    else
    {
        q->rear = (q->rear + 1)%q->size;//-1 se badhana hoga pehle na.
        q->Q[q->rear] = data;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if( isQueueEmpty(*q) )
        printf("\nQueue Underflow\n");
    else
    {
        q->front = (q->front + 1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

#endif