#include <iostream>
using namespace std;

void fun4(int n)
{
    if(n>0)
    {
        printf("%d\n", n);
        fun4(n-1);
        fun4(n-1);
    }
}

int main()
{

    fun4(3);
    return 0;
}