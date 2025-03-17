#include <iostream>
using namespace std;

double tserd(int x, int n)
{
    static int denom = n+1;
    double r;
    if(n == 0)
        return 1;
    r = tserd(x, n-1);
    denom--;
    return (1+x*(r/denom));
}

int main()
{
    printf("%lf\n", tserd(4,10));
    return 0;
}