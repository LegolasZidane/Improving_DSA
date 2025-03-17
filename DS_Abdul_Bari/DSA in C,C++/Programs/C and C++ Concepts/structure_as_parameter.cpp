#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

struct Rectangle * fun()
{
    struct Rectangle *p = new Rectangle;
    //struct Rectangle *p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 10;
    p->breadth = 5;

    return p;
}

int main()
{
    struct Rectangle *ptr = fun();

    cout<<endl<<"Length = "<<ptr->length<<endl<<"Breadth = "<<ptr->breadth<<endl;

    return 0;
}