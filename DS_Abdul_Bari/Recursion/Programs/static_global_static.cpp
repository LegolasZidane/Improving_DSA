#include <iostream>
using namespace std;

int fun3(int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        return fun3(n-1)+x;
    }
    return 0;
}

int main()
{
    printf("%d\n", fun3(5));
    return 0;
}