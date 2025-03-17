#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "stack.h"

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    createQueue(q, 100);

    printf("\nEnter root value\n");
    scanf("%d",&x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(q, root);

    while( !isQueueEmpty(*q) )
    {
        p = dequeue(q);
        printf("\nEnter left child of %d\n",p->data);
        scanf("%d",&x);
        if( x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(q, t);
        }
        printf("\nEnter right child of %d\n",p->data);
        scanf("%d",&x);
        if( x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(q, t);
        }
    }
}

void preorder(struct Node *r)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    createStack(s, 100);
    while( r!= NULL || !isStackEmpty(s) )
    {
        if( r!= NULL)
        {
            printf("%d->", r->data);
            push(s, r);
            r = r->lchild; 
        }
        else
        {
            r = pop(s);
            r = r->rchild;
        }
    }
    printf("\n");
}

void inorder(struct Node *r)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    createStack(s, 100);
    while( r!= NULL || !isStackEmpty(s) )
    {
        if( r!= NULL)
        {
            push(s, r);
            r = r->lchild; 
        }
        else
        {
            r = pop(s);
            printf("%d->", r->data);
            r = r->rchild;
        }
    }
    printf("\n");
}

//Will come back to postorder hopefully, Insha Allah!//

void levelOrderTraversal(struct Node *r)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    createQueue(q, 100);
    
    enqueue(q, root);
    printf("%d->", root->data);
    
    while( !isQueueEmpty(*q) )
    {
        r = dequeue(q);
        if( r->lchild != NULL)
        {
            printf("%d->", r->lchild->data);
            enqueue(q, r->lchild);
        }
        if( r->rchild != NULL)
        {
            printf("%d->", r->rchild->data);
            enqueue(q, r->rchild);
        }
    }
}

void preorderRecursive(struct Node *r)
{
    if( r == NULL )
        return;
    else
    {
        printf("%d->",r->data);
        preorderRecursive(r->lchild);
        preorderRecursive(r->rchild);
    }
}

void inorderRecursive(struct Node *r)
{
    if( r == NULL )
        return;
    else
    {
        inorderRecursive(r->lchild);
        printf("%d->",r->data);
        inorderRecursive(r->rchild);
    }
}

void postorderRecursive(struct Node *r)
{
    if( r == NULL )
        return;
    else
    {
        postorderRecursive(r->lchild);
        postorderRecursive(r->rchild);
        printf("%d->",r->data);
    }
}

/*int countNodes(struct Node *r)
{
    if( r != NULL )
    {
        int x = countNodes(r->lchild);
        int y = countNodes(r->rchild);
        return x+y+1;
    }
    else
        return 0;
}*/

int countNodes(struct Node *r)
{
    if( r == NULL )
        return 0;
    else
        return countNodes(r->lchild) + countNodes(r->rchild) + 1;
}

int countTwoDegreeNodes(struct Node *r)
{
    if( r != NULL )
    {
        int x = countTwoDegreeNodes(r->lchild);
        int y = countTwoDegreeNodes(r->rchild);
        if(r->lchild != NULL && r->rchild != NULL )
            return x+y+1;
        else
            return x+y;
    }
    else
        return 0;
}

/*int sumOfNodes(struct Node *r)
{
    if ( r == NULL )
        return 0;
    else
    {
        int x = sumOfNodes(r->lchild);
        int y = sumOfNodes(r->rchild);
        return x+y+r->data;
    }
}
*/

int sumOfNodes(struct Node *r)
{
    if( r == NULL )
        return 0;
    else
        return sumOfNodes(r->lchild) + sumOfNodes(r->rchild) + r->data;
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

int countLeafNodes(struct Node *r)
{
    if( r == NULL )
        return 0;
    else
    {
        int x = countLeafNodes(r->lchild);
        int y = countLeafNodes(r->rchild);
        if( r->lchild == NULL && r->rchild == NULL )
            return x+y+1;
        else
            return x+y;
    }
}

int countInternalNodes(struct Node *r)
{
    if( r == NULL )
        return 0;
    else
    {
        int x = countLeafNodes(r->lchild);
        int y = countLeafNodes(r->rchild);
        if( r->lchild != NULL || r->rchild != NULL )
            return x+y+1;
        else
            return x+y;
    }
}

int countOneDegreeNodes(struct Node *r)
{
    if( r == NULL )
        return 0;
    else
    {
        int x = countLeafNodes(r->lchild);
        int y = countLeafNodes(r->rchild);
        if( ( r->lchild != NULL )^( r->rchild != NULL ) ) //lchild NULL ho rchild na ho and vice versa.
            return x+y+1;
        else
            return x+y;
    }
}

int main()
{
    createTree();

    //postorder(root);
    //levelOrderTraversal(root);

    printf("\nNumber of nodes in the tree = %d\n", countNodes(root));
    printf("\nNumber of two degree nodes in the tree = %d\n", countTwoDegreeNodes(root));
    printf("\nNumber of leaf nodes in the tree = %d\n", countLeafNodes(root));
    printf("\nNumber of internal nodes in the tree = %d\n", countInternalNodes(root));
    printf("\nSum of nodes of the tree = %d\n", sumOfNodes(root));
    printf("\nHeight of the tree = %d\n", height(root));
    
    return 0;
}