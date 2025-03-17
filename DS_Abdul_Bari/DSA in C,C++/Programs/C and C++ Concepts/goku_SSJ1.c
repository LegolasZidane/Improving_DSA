#include<stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *p, int length, int breadth)
{
    p->length = length;
    p->breadth = breadth;
}

void changeLength(struct Rectangle *p, int length)
{
    p->length = length;
}

int area(struct Rectangle *p)
{
    return p->length*p->breadth;
}

int main()
{
    struct Rectangle r;

    initialize(&r, 10, 5);
    printf("%d\n", area(&r));
    changeLength(&r, 15);
    printf("%d\n", area(&r));

    return 0;
}