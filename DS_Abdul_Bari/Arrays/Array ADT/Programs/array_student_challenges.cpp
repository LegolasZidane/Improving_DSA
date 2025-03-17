#include <iostream>
using namespace std;

struct Array
{
    int A[5];
    int size;
    int length;
};

void multipleMissingElementsSorted(struct Array arr)
{
//Check adjacent elements, agar gap greater than 1
//toh missing and jitna bada utna missing. Also
//smaller mei add karte jao, wahi missing.
    int i , j, k;
    printf("\n Missing element/s are \n");
    for( i = 0; i<arr.length - 1; i++)
    {
        k = arr.A[i+1] - arr.A[i];
        if( k != 1)
        {
            for( j = 1; j<k; j++)
                printf("%d ", arr.A[i] + j);
        }
    }

}

void multipleMissingElementsUnsorted(struct Array arr)
{
//Unsorted mei using Hash array we map from min to max.
//Agar koi position mei value 0 hai, its missing.
    int min = arr.A[0], max = arr.A[0], i;
    for(i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
        else if(arr.A[i] < min)
            min = arr.A[i];
    }
    int length = max + 1 - min;
    int *H = (int *)malloc(length*sizeof(int)); // Has garbage values.
    for(i = 0; i<length; i++)
        H[i] = 0;
    for(i = 0; i<arr.length; i++)
        H[arr.A[i] - min]++;//important indexing formula.
    printf("\n Missing element/s are \n");
    for(i = 0; i<length; i++)
    {
        if(H[i]==0)
            printf("%d ",(i + min));
    }
}

void findingDuplicatesSorted(struct Array arr)
{//Simple hai, if adjacent elements are equal.
//Ye sirf duplicate bataraha, number of duplicates nahi.
//Issliye last duplicate yaad rakhna hona.

    int last_duplicate = 0, i;
    printf("\nDuplicates are \n");
    for( i = 0; i<arr.length - 1; i++)
    {
        if(arr.A[i] == arr.A[i+1] && last_duplicate != arr.A[i])
        {
            printf("%d ", arr.A[i]);
            last_duplicate = arr.A[i];
        }
    }
}

void countingDuplicatesUnsorted(struct Array arr)
{//Wahi Hash Table lekar solve karo, greater than 1
//pe print kardo along with the frequency.
    int min = arr.A[0], max = arr.A[0], i;
    for(i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
        else if(arr.A[i] < min)
            min = arr.A[i];
    }
    int length = max + 1 - min;
    int *H = (int *)malloc(length*sizeof(int)); 
    for(i = 0; i<length; i++)// Has garbage values.
        H[i] = 0;
    for(i = 0; i<arr.length; i++)
        H[arr.A[i] - min]++;
    printf("\n Duplicate element/s are \n");
    for(i = 0; i<length; i++)
    {
        if(H[i] > 1)
            printf("%d times %d\n", H[i],(i + min));
    }
}

void countingDuplicatesSorted(struct Array arr)
{//Adjacent check karo and if equal, ek naya pointer
//j lelo aur usko chalao till last duplicate ke baad
//phir i ko j-1 kardo and restart loop.

    int i , j;
    printf("\n Duplicate element/s are \n");
    for( i = 0; i<arr.length - 1; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            j = i+1;
            while(arr.A[j] == arr.A[i])
                j++;
            printf("%d times %d\n", arr.A[i], j-i);
            i = j-1;
        }
    }    
}

void findSumPairUnsorted(struct Array arr, int sum)
{//Wahi Hash Table use karke clever formula lagae.
//Array Element ka dusra part jisse sum bane, agar
//wo array mei hai to print them.
//Also isme mapping aur printing saath mei hona.

    int min = arr.A[0], max = arr.A[0], i;
    for(i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
        else if(arr.A[i] < min)
            min = arr.A[i];
    }
    int length = max + 1 - min;
    int *H = (int *)malloc(length*sizeof(int)); 
    for(i = 0; i<length; i++)// Has garbage values.
        H[i] = 0;
    printf("\nPairs with sum %d are \n", sum);
    for(i = 0; i<arr.length; i++)
    {
        if(H[sum - arr.A[i] - min] == 1)
            printf("%d, %d\n", arr.A[i], sum - arr.A[i]);
        H[arr.A[i]-min]++;//mapping hua nahi, yaha horaha!
    }
}

void findSumPairSorted(struct Array arr, int sum)
{//Two pointer concept. Sum chota to i ko badhao
// aur sum bada to j ko kam karo.

    int i = 0, j = arr.length - 1;
    printf("\nPairs with sum %d are \n", sum);
    while(i<j)//Increasing order mei array.
    {
        if(arr.A[i] + arr.A[j] == sum)
        {
            printf("%d, %d\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < sum)
            i++;
        else
            j--;
    }
}

void display(struct Array arr)
{
    int i;
    for( i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array a = {{1,1,1,2,2}, 10, 5};
    countingDuplicatesSorted(a);

    return 0;
}