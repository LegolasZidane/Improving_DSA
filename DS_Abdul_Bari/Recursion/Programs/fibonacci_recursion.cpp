#include <iostream>
using namespace std;

int fr(int n)
{
    if(n <= 1) 
        return n;
    return fr(n-2) + fr(n-1);
}

int main()
{
    printf("%d\n", fr(6));
    return 0;
}