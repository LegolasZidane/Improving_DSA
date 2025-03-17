#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL;

void create(int A[], int n)
{
    struct Node *last, *t = (struct Node *)malloc(sizeof(struct Node));
    int i;

    t->prev = t;
    t->data = A[0];
    t->next = t;
    head = last = t;

    for( i = 1; i < n; i++)
    {
        t =  (struct Node *)malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
        head->prev = last;//Important, loop ban gaya tha 0 aur 1 ke beech.
    }
}

void insert(struct Node *p, int data, int pos)
{
    struct Node *q;
    int i;

    if( pos == 0)
    {
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->prev = head->prev;
        q->data = data;
        q->next = head;
        q->prev->next = q;
        q->next->prev = q;
        head = q;
    }
    else
    {
        for( i = 0; i < pos-1; i++)
            p = p->next;
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->prev = p;
        q->data = data;
        q->next = p->next;
        p->next = q;
        if( q->next != NULL )
            q->next->prev = q;
    }
}

int delete(struct Node *p, int pos)
{
    struct Node *q;
    int i,x = 0;

    if( pos == 1 )
    {
        q = p;
        x = q->data;
        q->next->prev = q->prev;
        q->prev->next = q->next;
        head = q->next;
        q->prev = NULL;
        q->next = NULL;
        free(q);
        q = NULL;
    }
    else
    {
        for(i = 0; i < pos-1; i++)
            p = p->next;
        q = p;
        q->prev->next = q->next;
        q->next->prev = q->prev;
        q->prev = NULL;
        q->next = NULL;
        x = q->data;
        free(q);
        q = NULL;
    }
    return x;
}

void display(struct Node *p)
{
    do
    {
        printf("%d->", p->data);
        p = p->next;
    }while( p != head);
    printf("\n");
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    //display(head);

    /*insert(head, 55, 5);
    display(head);*/

    display(head);
    insert(head, 55, 5);
    display(head);
    delete(head, 6);
    display(head);
    
    return 0;
}