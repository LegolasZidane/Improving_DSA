#include<iostream>
using namespace std;

int * fun(int size)
{
    int *p = new int[size];

    for(int i = 0; i<size; i++)
    p[i] = i+1;

    return p;
}

int main()
{
    int *p, size = 5;
    p = fun(size);

    for(int i=0; i<size; i++)
    cout<<p[i]<<endl;

    return 0;
}