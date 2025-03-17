#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL, *second = NULL, *third = NULL, *Head = NULL;//global pointer

void create(int A[], int n)
{
    int i;
    struct Node *t, *tail;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    
    first->next = NULL;
    tail = first;//first abh first hi rahega aur pura kaam last karega, Insha Allah!

    for(i = 1; i < n; i++ )
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *tail;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    
    second->next = NULL;
    tail = second;//first abh first hi rahega aur pura kaam last karega, Insha Allah!

    for(i = 1; i < n; i++ )
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

int countNodes(struct Node *p)
{
    int count = 0;
    while( p != NULL )
    {
        count++;
        p = p->next;
    }
    return count;
}

int countNodesRecursive(struct Node *p)
{

    if( p == NULL)
        return 0;
    else
        return 1+(countNodesRecursive(p->next));

}

int sumNodes(struct Node *p)
{
    int sum = 0;
    while( p != NULL )
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int sumNodesRecursive(struct Node *p)
{

    if( p == NULL)
        return 0;
    else
        return p->data +(sumNodesRecursive(p->next));

}

int max(struct Node *p)
{
    int max = INT_MIN;
    while( p != NULL )
    {
        if(max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

int maxRecursive(struct Node *p)
{
    static int max = INT_MIN;
    if( p == NULL )
        return max;
    else
    {
        if( max < p->data)
            max = p->data;
        return maxRecursive(p->next);
    }
}

int maxRecursivePro(struct Node *p)
{
    int x = 0;
    if( p == NULL )
        return INT_MIN;
    else
    {
        x = maxRecursivePro(p->next);
        if( x < p->data )
            return p->data;
        else
            return x;
    }
}

int maxRecursiveProMax(struct Node *p)
{
    int x = 0;
    if( p == NULL )
        return INT_MIN;
    x = maxRecursivePro(p->next);
    return (x > p->data)?x:p->data;
}

struct Node * search(struct Node *p, int key)
{
    while( p != NULL )
    {
        if( key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node * searchRecursive(struct Node *p, int key)
{
    if( p == NULL)
        return NULL;
    if( p->data == key )
        return p;
    return searchRecursive(p->next, key);
}

struct Node * searchMoveToHead(struct Node *p, int key)
{
    struct Node *q = NULL;
    while( p != NULL )
    {
        if( p->data == key )
        {
            q->next = p->next;//Tail ko p ke baad se connect
            p->next = first;//First node ban gaya p
            first = p;//First node naya store karna hoga na.
            return first;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert(struct Node *p, int data, int pos)
{
    if( pos < 0 || pos > countNodes(p))
        return;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node *));
    t->data = data;
    if(pos == 0)
    {
        t->next = p;
        first = t;
    }
    else
    {
        for(int i = 0; i<pos-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insertLast(int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    if(first == NULL)
        first=last=t;
    else
    {
        last->next = t;
        last = t;
    }
}

void insertSortedList(struct Node *p, int data)
{
    struct Node *q = NULL, *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    
    if( first == NULL )
        first = t;
    else
    {
        while( p != NULL && p->data < data )
        {
            q = p;
            p = p->next;
        }
        if( p == first )
        {
            t->next = first;
            first = t;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
}

int delete(struct Node *p, int pos)
{
    struct Node *q = NULL;
    int x;
    if( p == NULL || pos < 1 || pos > countNodes(first))
        return -1;
    if( pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i = 0; i < pos-1 ; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while( p != NULL )
    {
        if( p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicatesSorted(struct Node *p)
{
    struct Node *q = p;
    p = p->next;
    while( p != NULL )
    {
        if( p->data != q->data)
        {
            q = p;
            p = p->next;
        }
        else
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
}

void reverse(struct Node *p)
{
    struct Node *q = p;
    int *A = (int *)malloc(countNodes(p)*sizeof(int));
    int i=0;

    while( q != NULL)
    {
        A[i++] = q->data;
        q = q->next; 
    }
    i--;
    q = p;
    while( q != NULL )
    {
        q->data = A[i--];
        q = q->next;
    }
}

void reverseEnhanced(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while( p != NULL )
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseRecursive(struct Node *p, struct Node *q)
{
    if( p == NULL)
        first = q;
    else
    {
        reverseRecursive(p->next, p);
        p->next = q;
    }
}

void concatenation(struct Node *first, struct Node *second)
{
    struct Node *q = first;
    while( q->next != NULL )
        q = q->next;
    q->next = second;
}

void merging(struct Node *f, struct Node *s)
{
    struct Node *tail;
    if( f->data < s->data)
    {
        third = tail = f;
        f = f->next;
        tail->next = NULL;
    }
    else
    {
        third = tail = s;
        s = s->next;
        tail->next = NULL;
    }
    while( f != NULL && s != NULL )
    {
        if( f->data < s->data)
        {
            tail->next = f;
            tail = f;
            f = f->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = s;
            tail = s;
            s = s->next;
            tail->next = NULL;
        }
        if( f != NULL)
            tail->next = f;
        else
            tail->next = s;
    }
}

int isLoop(struct Node *p)
{
    struct Node *q = p, *r = p;
    
    if( p == NULL)
        return -1;
    
    do
    {
        q = q->next;
        r = r->next;
        r = r != NULL ? r->next : NULL;
        if( r == q)
            return 1;   
    }while(q != NULL && r != NULL);
    return 0;
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

void displayRecursive(struct Node *p)
{
    if( p != NULL )
    {
        printf("%d->", p->data);
        displayRecursive(p->next);
    }
}

int main()
{
    //struct Node *t1, *t2;
    
    int A[] = {10,20,30,40,50};
    //int B[] = {5,15,25,35,45};
    
    create(A, 5);
    //create2(B, 5);

    /*t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;*/

    /*if( isLoop(first) == 1 )
        printf("Loop present");
    else
        printf("No loop/ Linear Linked List");*/


    /*insertLast(10);
    display(first);
    insertLast(20);
    display(first);
    insertLast(30);
    display(first);
    insertLast(40);
    display(first);
    insertLast(50);
    display(first);*/

    /*display(first);
    insert(first, 16, 5);*/

    //insertSortedList(first, 16);
    //insertSortedList(first, 17);
    
    //delete(first, 5);
    
    //removeDuplicatesSorted(first);
    
    /*display(first);

    reverse(first);
    reverseEnhanced(first);
    reverseRecursion(first, NULL);*/

    /*display(first);
    concatenation(first, second);*/

    /*display(first);
    display(second);
    merging(first, second);
    display(third);*/

    //display(first);
    /*display(second);
    display(first);*/
    
    //printf("\nMaximum element of the linked list = %d\n", maxRecursiveProMax(first));
    
    //printf("\nlength of the linked list = %d\n", countNodesRecursive(first));
    
    //printf("\nsum of the linked list = %d\n", sumNodesRecursive(first)); 
    
    //displayRecursive(first);
    
    /*struct Node *temp;
    temp = searchMoveToHead(first, 15);
    if( temp != NULL)
        printf("\nElement found\n");
    else
        printf("\nElement not found\n");
    display(first);*/

    /*if( isSorted(first) == 1 )
        printf("Sorted");
    else
        printf("Not sorted");*/

    

    return 0;
}