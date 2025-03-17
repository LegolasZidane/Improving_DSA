#include <iostream>
using namespace std;

int C(int n, int r)
{
    if(r == 0 || n == r)
        return 1;
    return C(n-1,r-1) + C(n-1,r);
}

int main()
{
    printf("%d\n", C(5,1));
    return 0;
}