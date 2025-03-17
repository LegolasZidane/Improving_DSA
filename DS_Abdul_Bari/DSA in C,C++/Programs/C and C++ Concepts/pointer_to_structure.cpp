#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    /*Rectangle r = {10,5};
    cout<<endl<<r.length<<endl;
    cout<<r.breadth<<endl; stack mei static object ka example*/

    Rectangle *p;
    p = new Rectangle;//(struct Rectangle *)malloc(sizeof(struct Rectangle));//Heap memory mei ye hai

    p->length = 10;
    p->breadth = 5;


    cout<<endl<<p->length<<endl;
    cout<<p->breadth<<endl;

    return 0;
}