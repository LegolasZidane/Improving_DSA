#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

int isEmpty()
{
    if( front == NULL )
        return 1;
    else
        return 0;
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if( t == NULL )
        return 1;
    else
        return 0;
}

void enqueue(int data)
{
    if( isFull() )
        printf("\nQueue Overflow\n");
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        if( front == NULL )
            front = rear = p;
        else
        {
            rear->next = p;
            rear = p;
        } 
    }
}

int dequeue()
{
    int x = -1;
    if( isEmpty() )
        printf("\nQueue Underflow\n");
    else
    {
        struct Node *p = front;
        front = front->next;
        x = p->data;
        p->next = NULL;
        free(p);
        p = NULL;
    }
    return x;
}

void display()
{
    if( isEmpty() )
        printf("\nQueue Underflow\n");
    else
    {
        printf("\nQueue Element/s\n");
        struct Node *p = front;
        while( p!= NULL )
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    display();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    enqueue(4);
    display();
    dequeue();
    display();
    dequeue();
    display();

    return 0;
}