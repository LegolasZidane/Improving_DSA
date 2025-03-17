#include<iostream>
using namespace std;

int add(int a,int b)//Formal parameters
{
    int c = a + b;
    return c;
}

int main()
{
    int num1 = 10, num2 = 15, sum;
    
    sum = add(num1, num2);//Actual parameters

    cout<<endl<<"Sum is = "<<sum<<endl;

    return 0;
}