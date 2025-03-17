#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x; //Padding ka example
};


int main()
{
    struct Rectangle r1;

    r1.length = 10;
    r1.breadth = 5;

    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;

    return 0;
}