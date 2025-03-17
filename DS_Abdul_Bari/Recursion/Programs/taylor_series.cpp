#include <iostream>
using namespace std;

double taylor(int x, int n)
{
    static double p = 1, f = 1; // taaki har time value change na ho jaisa humko chahiye waise rahe
    double r;
    if(n == 0)
        return 1;
    r = taylor(x, n-1); // yaha par call basically descending phase of recursion important kyuki peeche se aage aana hai.
    p = p*x;
    f = f*n;
    return (r + p/f);
}

int main()
{
    printf("%lf\n", taylor(4,10));
    return 0;
}