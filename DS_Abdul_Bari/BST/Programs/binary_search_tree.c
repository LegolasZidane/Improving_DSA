#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

/*struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;*/

struct Node *root = NULL;

struct Node *search(struct Node *q, int key)
{
    while( q != NULL )
    {
        if( q->data == key )
            return q;
        else if( q->data > key)
            q = q->lchild;
        else
            q = q->rchild;
    }
    return q;
}

int searchRecursive(struct Node *q, int key)
{
    if( q == NULL )
        return 0;
    else if( q->data == key)
        return 1;
    else if( q->data < key )
        return searchRecursive(q->rchild, key);
    else
        return searchRecursive(q->lchild, key);
}

void insert(struct Node *q, int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if( root == NULL )
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->lchild = p->rchild = NULL;
        p->data = key;
        root = p;
    }
    while( t != NULL )
    {
        r = t;
        if( t->data < key )
            t = t->rchild;
        else if( t->data > key )
            t = t->lchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->lchild = p->rchild = NULL;
    p->data = key;

    if( key < r->data )
        r->lchild = p;
    else
        r->rchild = p;
}

struct Node *insertRecursive(struct Node *q, int key)
{
    if( q == NULL )
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->lchild = p->rchild = NULL;
        p->data = key;
        return p;
    }
    if( key < q->data )
        q->lchild = insertRecursive(q->lchild, key);
    if( key > q->data )
        q->rchild = insertRecursive(q->rchild, key);
    return NULL; 
}

struct Node *inorderPredecessor(struct Node *r)
{
    if( r->rchild == NULL )
        return r;
    else
        return inorderPredecessor(r->rchild);
}

struct Node *inorderSuccessor(struct Node *r)
{
    if( r->lchild == NULL )
        return r;
    else
        return inorderSuccessor(r->lchild);
}

int height(struct Node *r)
{
    if( r == NULL )
        return 0;
    else
    {
        int x = height(r->lchild);
        int y = height(r->rchild);
        if( x > y )
            return x+1;
        else
            return y+1; 
    }
}

struct Node *deleteNode(struct Node *p, int key)
{//Delete kya hoga pehle cases banao.
//1 node, leaf node, ya wo extreme case.
//DELETE LEAF HI HORAHA, BAS VALUE COPY HO RAHA!
//Node ki address return karni padegi after delete.
//Itna jhamela only for the leaf se pehle ki updation.
    struct Node *q;
    //Actual DELETION happens here.
    if( p == NULL )
        return NULL;
    if( p->lchild == NULL && p->rchild == NULL )
    {
        if( p == root )
            root = NULL;
        free(p);
        p = NULL;
        return p;
    }
    //Searching process
    if( key < p->data )
        p->lchild = deleteNode(p->lchild, key);
    else if( key > p->data )
        p->rchild = deleteNode(p->rchild, key);
    else
    {
        //Replacing the node process here.
        if( height(p->lchild) > height(p->rchild) )
        {
            q = inorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = deleteNode(p->lchild, q->data);
        }
        else
        {
            q = inorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = deleteNode(p->rchild, q->data);
        }
    }
    return p;
}

void createFromPre(int pre[], int n)
{
    struct Node *p=NULL, *t;
    struct Stack *s;
    int i = 1;
    createStack(s, 10);

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = pre[0];
    t->lchild = t->rchild = NULL;
    root = p = t;
    while( i < n )
    {
        if( t->data < p->data )
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(s, p);
            p = t;
            i++;
        }
        else if( t->data > p->data && t->data < peek(s) )
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            p = t;
            i++;
        }
        else
        {
            p = pop(s);
        }
    }
}

void inorder(struct Node *p)
{
    if( p == NULL )
        return;
    else
    {
        inorder(p->lchild);
        printf("%d->", p->data);
        inorder(p->rchild);
    }
}

int main()
{
    /*insert(root, 10);
    insert(root, 90);
    insert(root, 20);
    insert(root, 80);
    insert(root, 30);
    insert(root, 70);*/


    //deleteNode(root, 10);

    //inorder(root);

    int ap[] = {30,20,10,15,25,40,50,45};
    createFromPre(ap, 8);
    inorder(root);

    return 0;
}