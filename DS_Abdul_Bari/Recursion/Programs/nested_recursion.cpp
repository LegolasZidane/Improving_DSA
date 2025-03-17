#include <iostream>
using namespace std;

int fun5(int n)
{
    if(n>100)
        return n-10;
    return fun5(fun5(n+11));
}

int main()
{
    printf("%d\n", fun5(95));
    return 0;
}
