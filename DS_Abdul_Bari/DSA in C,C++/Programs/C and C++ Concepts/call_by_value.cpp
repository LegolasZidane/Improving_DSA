#include<iostream>
using namespace std;

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    cout<<endl<<"Values of x and y are "<<endl<<x<<endl<<y<<endl;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(a,b);
    cout<<endl<<"Values of a and b are "<<endl<<a<<endl<<b<<endl;

    return 0;
}
//Call by value mei as you can see actual parameters change nahi hote hain.