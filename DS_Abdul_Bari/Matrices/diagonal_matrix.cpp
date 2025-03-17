#include <iostream>
using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if(i == j)
        m->A[i - 1] = x;
}

int get(struct Matrix m, int i, int j)
{
    if(i == j)
        return m.A[i-1];
    else
        return 0;
}

void display(struct Matrix m)
{
    int i, j;
    for(i = 1; i<=m.n; i++)
    {
        for(j = 1; j<=m.n; j++)
        {
            if(i == j)
                printf("%d ", m.A[i-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix a = {{1,2,3,4,5},5};
    display(a);

    return 0;
}