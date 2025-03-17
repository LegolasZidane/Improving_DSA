#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for( i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int countNodes(struct Node *p)
{
    int count = 0;
    if( p == NULL)
        return count;
    else
    {
        do
        {
            count++;
            p = p->next;
        }while(p != head);
        
        return count;
    }
}

void insert(struct Node *p, int data, int pos)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int i;
    t->data = data;
    if( pos == 0)
    { 
        if( head == NULL )
        {
            head = t;
            t->next = t;
        }
        else// yaha gadbadi hui 2-3 baar, Alhamdulilah!
        {
            while( p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else if( pos <= countNodes(head))
    {
        for(i = 0; i < pos-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int delete(struct Node *p, int pos)
{
    struct Node *q;
    int i, x = 0;
    if( pos == 1 )
    {
        if( countNodes(head) == 1 )
        {
            x = head->data;
            free(head);
            head = NULL;
        }
        else
        {
            while( p->next != head)
                p = p->next;
            p->next = head->next;
            x = head->data;
            free(head);
            head = p->next;
            return x;
        }
    }
    else if( pos <= countNodes(head))
    {
        for( i = 0; i < pos-2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
        q = NULL;
        return x;
    }
}

void displayCircular(struct Node *p)
{
    do
    {
        printf("%d->", p->data);
        p = p->next;
    }while( p != head );
    printf("\n");
}

void displayCircularRecursive(struct Node *p)
{
    static int flag = 0;
    if( p != head || flag == 0)
    {
        flag = 1;
        printf("%d->", p->data);
        displayCircularRecursive(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    displayCircular(head);
    //displayCircularRecursive(head);

    /*insert(head, 55, 5);
    displayCircular(head);*/

    printf("\nNumber deleted is = %d\n", delete(head, 5));
    displayCircular(head);
    return 0;
}