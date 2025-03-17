#include <iostream>
using namespace std;

int steps = 0;
void tohr(int n, int A, int B, int C)
{
    static char name[4] = {' ', 'A', 'B', 'C'};
    if(n > 0)
    {
        tohr(n-1, A, C, B);
        printf("%c to %c\n", name[A], name[C]);
        steps++;
        tohr(n-1, B, A, C);
    }
}

int main()
{
    tohr(4, 1, 2, 3);
    printf("%d\n", steps);
    return 0;
}