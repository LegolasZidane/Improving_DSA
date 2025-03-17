#include<iostream>
using namespace std;

int main()
{
    int a = 10; //in stack memory
    int *p = &a; //in stack memory
    //in c we write int *p = (int *)malloc(5 * sizeof(int));
    //both are in heap memory.
    //in c++ we write int *p = new int[5];

    cout<<endl<<p<<endl;
    cout<<*p<<endl;

    //in c we write free(p); important for large scale development
    //in c++ we write delete [ ] p;

    return 0;
}