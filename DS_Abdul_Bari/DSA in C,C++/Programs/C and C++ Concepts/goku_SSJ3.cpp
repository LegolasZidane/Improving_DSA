#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    
    public:
        Rectangle();
        Rectangle(int l, int b);
        int area();
        int perimeter();
        int getLength();
        int getBreadth();
        void setLength(int l);
        void setBreadth(int b);
        ~Rectangle();
};

Rectangle::Rectangle()
{
    length = breadth = 0;
}

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::area()
{
    return length*breadth;
}

int Rectangle::perimeter()
{
    return (2*(length + breadth));
}

int Rectangle::getLength()
{
    return length;
}

int Rectangle::getBreadth()
{
    return breadth;
}

void Rectangle::setLength(int l)
{
    length = l;
}

void Rectangle::setBreadth(int b)
{
    breadth = b;
}

Rectangle::~Rectangle()
{
}

int main()
{
    Rectangle r(10,5);

    cout<<endl<<r.area()<<endl;
    cout<<endl<<r.perimeter()<<endl;

    r.setLength(15);
    cout<<endl<<r.getLength()<<endl;


    return 0;
}