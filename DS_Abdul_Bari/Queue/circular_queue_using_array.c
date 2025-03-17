#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct Queue *q)
{
    printf("\nEnter the size of the Queue\n");
    scanf("%d",&(q->size));
    
    q->Q = (int *)malloc((q->size)*sizeof(int));

    q->front = q->rear = 0;//Important
}

int isEmpty(struct Queue q)
{
    if( q.front == q.rear )
        return 1;
    else
        return 0;
}

int isFull(struct Queue q)
{
    if( (q.rear+1)%q.size == q.front )
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, int data)
{
    if( isFull(*q) )
        printf("\nQueue Overflow\n");
    else
    {
        q->rear = (q->rear + 1)%q->size;//-1 se badhana hoga pehle na.
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if( isEmpty(*q) )
        printf("\nQueue Underflow\n");
    else
    {
        q->front = (q->front + 1)%q->size;
        x = q->front;
    }
    return x;
}

void display(struct Queue q)
{
    if( isEmpty(q) )
        printf("\nQueue Underflow\n");
    else
    {
        int i = q.front; 
        printf("\nQueue Element/s\n");
        while( i != q.rear )
        {
            i = (i + 1)%q.size;
            printf("%d ", q.Q[i]);
        } 
        printf("\n");
    }
}

int main()
{
    struct Queue *q1;
    create(q1);
    display(*q1);
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    display(*q1);
    dequeue(q1);
    display(*q1);
    dequeue(q1);
    display(*q1);
    dequeue(q1);
    display(*q1);


    return 0;
}