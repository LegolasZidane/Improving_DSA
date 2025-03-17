#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *st;
};

void create(struct Stack *s)
{
    printf("\nEnter the size of the stack\n");
    scanf("%d",&(s->size));

    s->top = -1;
    s->st = (int *)malloc((s->size)*sizeof(int));
}

int isEmpty(struct Stack s)
{
    if( s.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack s)
{
    if( s.top == s.size - 1 )
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int x)
{
    if( isFull(*s) )
        printf("\nStack Overflow\n");
    else
    {
        s->top++;
        s->st[s->top] = x;
    }
}

int pop(struct Stack *s)
{
    int x = -1;
    if( isEmpty(*s) )
        printf("\nStack Underflow\n");
    else
        x = s->st[s->top--];
    return x;
}

void peek(struct Stack s, int pos)
{
    if( isEmpty(s) )
        printf("\nStack Underflow\n");
    else if( s.top-pos+1 < 0 || s.top-pos+1 > s.top)
        printf("\nInvalid position\n");
    else
        printf("\nValue = %d", s.st[s.top-pos+1]);
}

void stackTop(struct Stack s)
{
    if( isEmpty(s) )
        printf("\nStack Underflow\n");
    else
        printf("\n%d", s.st[s.top]);
}

void display(struct Stack s)
{
    if( isEmpty(s) )
        printf("\nStack Underflow\n");
    else
    {
        printf("\nStack Element/s\n");
        for(int i = s.top; i>=0; i--)
            printf("%d\n", s.st[i]);
    }
}

int main()
{
    /*struct Stack s1;
    create(&s1);
    display(s1);
    push(&s1, 1);
    display(s1);
    push(&s1, 2);
    display(s1);
    push(&s1, 3);
    display(s1);
    pop(&s1);
    display(s1);
    pop(&s1);
    display(s1);
    pop(&s1);
    display(s1);*/



    return 0;
}