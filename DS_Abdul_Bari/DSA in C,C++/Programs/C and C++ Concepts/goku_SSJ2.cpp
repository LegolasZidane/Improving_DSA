#include<iostream>
using namespace std;

class Rectangle
{

private:
    int length;
    int breadth;

public:

/*void initialize(int l, int b)
{
    length = l;
    breadth = b;
}*/
Rectangle()
{
    length = 0;
    breadth = 0;
}
Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

void changeLength(int l)
{
    length = l;
}

int area()
{
    return length*breadth;
}

};

int main()
{
    Rectangle r(10,5);

    //r.initialize(10,5);
    cout<<endl<<r.area()<<endl;
    r.changeLength(15);
    cout<<endl<<r.area()<<endl;

    return 0;
}