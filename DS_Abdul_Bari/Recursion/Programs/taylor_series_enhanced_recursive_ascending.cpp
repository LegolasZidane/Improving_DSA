#include <iostream>
using namespace std;

double tsera(int x, int n) // Loop ki tarah hi to use kiya hai bhaiya
{
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + x*(s/n); // acha use of static variable, similar to that sum and product variable in loops.
    return tsera(x, n-1);
}

int main()
{
    printf("%lf\n", tsera(4,10));
    return 0;
}