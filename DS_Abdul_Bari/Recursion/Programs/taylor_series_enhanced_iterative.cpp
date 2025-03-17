#include <iostream>
using namespace std;

double tsei(int x, int n)
{
    double s = 1;
    for(; n>0 ; n--)
        s = 1 + x*(s/n);
    return s;
}

int main()
{
    printf("%lf\n", tsei(4,10));
    return 0;
}