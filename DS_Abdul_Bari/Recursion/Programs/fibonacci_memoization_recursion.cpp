#include <iostream>
using namespace std;

int F[10];
int fmr(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-1] == -1)
            F[n-1] = fmr(n-1);
        if(F[n-2] == -1)
            F[n-2] = fmr(n-2);
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
    
}

int main()
{
    for(int i = 0; i<10; i++)
        F[i] = -1;
    printf("%d\n", fmr(6));
    return 0;
}