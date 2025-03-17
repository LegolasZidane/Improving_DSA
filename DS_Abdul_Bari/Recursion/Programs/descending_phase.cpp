#include <iostream>
using namespace std;

//This can also be used as an example of head recusion.
void fun2(int n)
{
    if(n>0)
    {
        fun2(n-1);
        printf("%d\n", n);//Execution during returning time of the function is called descending phase of the recursive function.
    }
}

int main()
{
    fun2(5);
    return 0;
}