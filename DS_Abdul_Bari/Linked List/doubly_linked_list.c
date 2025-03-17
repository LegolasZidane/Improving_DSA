#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    struct Node *last, *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[0];
    t->next = NULL;
    t->prev = NULL;
    first = last = t;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;//Relation banaoge, tabh na aage badhoge.
        last = t;
    }
}

int length(struct Node *p)
{
    int count = 0;
    while( p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct Node *p, int data, int pos)
{
    struct Node *q;
    if( pos == 0)
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = data;
        q->prev = NULL;
        q->next = p;
        p->prev = q;
        first = q;
    }
    else
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = data;
        for(int i = 0; i < pos-1; i++)
            p = p->next;
        q->next = p->next;
        if( p->next != NULL )//Corner Case
            p->next->prev = q;
        q->prev = p;
        p->next = q;
    }
}

int delete(struct Node *p, int pos)
{
    int x = 0, i;
    struct Node *q;
    if( pos == 1)
    {
        if( first->next == NULL )
        {
            x = first->data;
            q = first;
            first = NULL;
            free(q);
            q = NULL;
        }
        else
        {
            q = first;
            first = first->next;
            first->prev = NULL;
            q->next = NULL;
            x = q->data;
            free(q);
            q = NULL;
        }
    }
    else
    {
        for( i = 0; i < pos-2; i++)//delete mei -2 lagta hai, waise -1 mei bhi hojaega
            p = p->next;
        q = p->next;
        x = q->data;
        if( q->next != NULL)//Bhai hosh sambhal le, galti 2 baar hogaya.
        q->next->prev = p;
        p->next = q->next;
        q->prev = q->next = NULL;
        free(q);
        q = NULL;
    }
    return x;
}

void reverse(struct Node *p)
{
    struct Node *swap;
    while( p != NULL)
    {
        swap = p->prev;
        p->prev = p->next;
        p->next = swap;
        if(p->prev == NULL)
            first = p;
        p = p->prev;
    }
}

void display(struct Node *p)
{
    while( p != NULL )
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    /*display(first);
    printf("\nLength of the LL = %d", length(first));*/

    /*insert(first, 55, 5);
    display(first);*/

    /*insert(first, 55, 5);
    display(first);
    //printf("%d", length(first));
    delete(first, 6);
    display(first);*/

    display(first);
    reverse(first);
    display(first);

    return 0;
}