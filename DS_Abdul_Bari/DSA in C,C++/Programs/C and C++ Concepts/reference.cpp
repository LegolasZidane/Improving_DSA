#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a;
    
    int b = 40;
    r = b;

    cout<<endl<<r<<endl<<a<<endl;

    return 0;
}