#include <iostream>
using namespace std;

struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    
    if(i >= j)
        m->A[i*(i-1)/2+j-1] = x;

}

int get(struct Matrix m, int i, int j)
{
    if(i >= j)
        return m.A[i*(i-1)/2+j-1];
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
            if(i >= j)
                printf("%d ", m.A[i*(i-1)/2+j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void displayArray(struct Matrix m)
{

    int size = m.n*(m.n+1)/2;
    for(int i = 0; i<size ; i++)
    {
        printf("%d ", m.A[i]);
    }

}

int main()
{
    struct Matrix m;
    int x;

    printf("Enter the size of the matrix");
    scanf("%d",&(m.n));

    m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));

    printf("Enter the elements in the 2D array");
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }
    printf("\n");
    display(m);
    printf("\n");
    displayArray(m);

    return 0;
}