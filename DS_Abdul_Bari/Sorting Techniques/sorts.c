#include<stdio.h>
#include<limits.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int A[], int n)
{//limits mei hi asal game
    int i, j, flag = 0;

    for( i = 0; i < n-1 ; i++ )
    {
        flag = 0;
        for( j = 0; j < n-1-i ; j++ )
        {
            if( A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if( flag == 0 )
            break;
    }
}

void insertionSort(int A[], int n)
{
//Element copy, ek place pehle se run.
//right shifting till place found.
//Copy element at the right place.
    int i, j, temp;
    for( i = 1; i < n ; i++ )
    {
        j = i - 1;
        temp = A[i];
        while( j > -1 && A[j] > temp )
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

void selectionSort(int A[], int n)
{
//Finding the minimum place and then swapping
//Apna 10 ka code kitna simple tha bhai.
//Iska advantage hai ki har paas mei 1 swap only.
    int i, j, k;
    for( i = 0; i < n-1; i++ )//n-1 tak behtar
    {
        for( j = k = i; j < n; j++ )
        {
            if( A[j] < A[k] )//k hoga i nahi
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h)
{
    int pivot = A[h];
    int i = l, j = h;

    do
    {
        do{i++;}while( i < h && A[i] <= pivot);
        do{j--;}while(j > l && A[j] > pivot);

        if( i < j ) swap(&A[i], &A[j]);
    } while(i<j);

    swap(&A[h],&A[i]);
    return i;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if( l < h )
    {
        j = partition(A,l,h);
        quickSort(A,l,j-1);
        quickSort(A,j,h);
    }
}

void merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    int B[100];
    i = low, j = mid+1, k = low;

    while( i <= mid && j <= high )
    {
        if( A[i] < A[j] )
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i <= mid; i++ )
        B[k++] = A[i];
    for(; j <= high; j++ )
        B[k++] = A[j];

    for( i = low; i <= high; i++ )
        A[i] = B[i];
}

void mergeSort(int A[], int n)
{
    int i, p, low, high, mid;

    for( p = 2; p <= n; p=p*2 )
    {
        for( i = 0; i+p-1 <= n; i = i + p )
        {
            low = i;
            high = i+p-1;
            mid = (low + high)/2;
            merge(A, low, mid, high);
        }
    }
    if( p/2 < n )
        merge(A, 0, p/2-1, n-1);

}

void mergeSortRecursive(int A[], int low, int high)
{
    int mid;
    if( low < high )
    {
        mid = (low + high)/2;
        mergeSortRecursive(A, low, mid);
        mergeSortRecursive(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

void display(int A[], int n)
{
    printf("\n");
    for( int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

}

int main()
{
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, n = 10;

    //bubbleSort(A, n);
    //insertionSort(A, n);
    //selectionSort(A, n);
    //quickSort(A,0,n-1);
    //mergeSort(A, n);
    mergeSortRecursive(A, 0, n-1);

    display(A, n);


    return 0;
}