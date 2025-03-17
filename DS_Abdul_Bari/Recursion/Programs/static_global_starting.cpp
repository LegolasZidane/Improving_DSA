#include <iostream>
using namespace std;

int fun3(int n)
{
    if(n>0)
    {
        return fun3(n-1)+n;
    }
    return 0;
}

int main()
{
    printf("%d\n", fun3(5));
    return 0;
}