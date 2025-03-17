#include<stdio.h>
#include<stdlib.h>

void insertHeap(int H[], int n)
{//Part of create heap so n ki fikr choro.
//n pe element ko check with its parent.
//Bada to keep on climbing else end.

    int temp, i = n;//n waise hi bheje miyan
    temp = H[n];
    while( i > 1 && temp > H[i/2] )//max heap
    {
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}

int deleteRoot(int H[], int n)
{/*Heap mei root delete hota hai.
Last becomes first and waha se
children mei checking hota hai
Keep on doing this, end mei
we store deleted value at end
which done for n, is HeapSort!*/

    int x, val, i, j, temp;
    val = H[1];
    x = H[n];
    H[1] = H[n];
    H[n] = val;
    i = 1, j = 2*i;
    while( j < n-1 )
    {
        if( H[j+1] > H[j] )
            j = j+1;
        if( H[i] < H[j] )
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2*j;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // 40, 25, 35, 10, 5, 20, 30
    int i;

    for( i = 2; i <= 7; i++ )
        insertHeap(H, i);

    for( i = 7; i>1; i--)
        deleteRoot(H, i);

    /*printf("Deleted Value = %d\n", deleteRoot(H, 7));
    printf("Deleted Value = %d\n", deleteRoot(H, 6));
    printf("Deleted Value = %d\n", deleteRoot(H, 5));
    printf("Deleted Value = %d\n", deleteRoot(H, 4));
    printf("Deleted Value = %d\n", deleteRoot(H, 3));
    printf("Deleted Value = %d\n", deleteRoot(H, 2));*/
    //printf("Deleted Value = %d", deleteRoot(H, 7));

    for( i = 1; i <= 7; i++ )
        printf("%d ", H[i]);

    return 0;
}