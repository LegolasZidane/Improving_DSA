#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*struct Stack
{
    int data;
    struct Stack *next;
}*top = NULL;*/

/*struct Stack
{
    char data;
    struct Stack *next;
}*top = NULL;*/

struct Stack
{
    char data;
    struct Stack *next;
}*top = NULL;

int isEmpty()
{
    return top? 0 : 1;
}

int isFull()
{
    struct Stack *t = (struct Stack *)malloc(sizeof(struct Stack)); 
    return t? 0 : 1;
}

/*void push(int x)
{
    if( isFull() )
        printf("\nStack Overflow\n");
    else
    {
        struct Stack *t = (struct Stack *)malloc(sizeof(struct Stack)); 
        t->data = x;
        t->next = top;
        top = t;
    }
}*/

/*void push(char x)//for paranthesis
{
    if( isFull() )
        printf("\nStack Overflow\n");
    else
    {
        struct Stack *t = (struct Stack *)malloc(sizeof(struct Stack)); 
        t->data = x;
        t->next = top;
        top = t;
    }
}*/

void push(char x)
{
    if( isFull() )
        printf("\nStack Overflow\n");
    else
    {
        struct Stack *t = (struct Stack *)malloc(sizeof(struct Stack)); 
        t->data = x;
        t->next = top;
        top = t;
    }
}

/*int pop()
{
    int x = -1;
    if( isEmpty() )
        printf("\nStack Underflow\n");
    else
    {
        struct Stack *t = top;
        x = t->data;
        top = t->next;
        t->next = NULL;
        free(t);
        t = NULL;
    }
    return x;
}*/

/*char pop()
{
    char x = ' ';
    if( isEmpty() )
        printf("\nStack Underflow\n");
    else
    {
        struct Stack *t = top;
        x = t->data;
        top = t->next;
        t->next = NULL;
        free(t);
        t = NULL;
    }
    return x;
}*/

char pop()
{
    char x = ' ';
    if( isEmpty() )
        printf("\nStack Underflow\n");
    else
    {
        struct Stack *t = top;
        x = t->data;
        top = t->next;
        t->next = NULL;
        free(t);
        t = NULL;
    }
    return x;
}

int isOperator(char x)
{
    if( x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    else
        return 0;
}

int precedence(char x)
{
    if( x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' )
        return 2;
}

char peek()
{
    if( isEmpty() )
        return -1;
    else   
    {
        struct Stack *t = top;
        return t->data;
    }
}

char * convertInfixToPostfix(char *infix)
{
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0, j = 0;
    
    while( infix[i] != '\0' )
    {
        if( isOperator(infix[i]) )
        {
            if( isEmpty() )
                push(infix[i++]);
            else if( precedence(peek()) < precedence(infix[i]) )//peek() ki jagah should've used top->data!
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
        else
            postfix[j++] = infix[i++];
    }
    while( !isEmpty() )
        postfix[j++] = pop();
    postfix[j++] = '\0';
    return postfix;
}

/*void display()
{
    if( isEmpty() )
        printf("\nStack Underflow\n");
    else
    {
        struct Stack *t = top;
        printf("\nStack Element/s\n");
        while(t)
        {
            printf("%d\n", t->data);
            t = t->next;
        }
    }
}*/

/*void display()
{
    if( isEmpty() )
        printf("\nStack Underflow\n");
    else
    {
        struct Stack *t = top;
        printf("\nStack Element/s\n");
        while(t)
        {
            printf("%c\n", t->data);
            t = t->next;
        }
    }
}*/

void display()
{
    if( isEmpty() )
        printf("\nStack Underflow\n");
    else
    {
        struct Stack *t = top;
        printf("\nStack Element/s\n");
        while(t)
        {
            printf("%c\n", t->data);
            t = t->next;
        }
    }
}

void displayString(char *p)
{
    printf("\n");
    int i = 0;
    while(p[i] != '\0')
        printf("%c", p[i++]);
    printf("\n");
}

/*int validParenthesis(char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')//bohot khatarnaak error
        {
            if( isEmpty() )
                return 0;
            else
                pop();
        }
    }
    if( isEmpty() )
        return 1;
    else
        return 0;
}*/

int main()
{
    /*display();
    pop();
    push(1);
    display();
    pop();
    display();
    push(1);
    push(2);
    push(3);
    display();*/

    /*char *expression = "((a+b)*(a+b))";
    if( validParenthesis(expression) )
        printf("Balanced");
    else
        printf("Not Balanced");*/

    char *expression = "a+b*c-d/e";
    char *postfix = convertInfixToPostfix(expression);
    displayString(expression);
    printf("%d",strlen(expression));//null is not included in length.
    displayString(postfix);
    return 0;
}