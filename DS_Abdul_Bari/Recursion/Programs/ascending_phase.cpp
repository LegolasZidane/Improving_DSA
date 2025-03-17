#include <iostream>
using namespace std;

//This can also be used as an example of tail recursion.
void fun1(int n)
{
    if(n>0)
    {
        printf("%d\n", n);//Execution during calling time of function is called ascending phase of the funciton.
        fun1(n-1);
    }
}
int main()
{
fun1(5);
return 0;
}