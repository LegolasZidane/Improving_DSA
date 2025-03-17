/*Before diving into this code, i want you to help you with your overall experience.
This program was written during the array ADT section of abdul bari's course on data structures and algorithms with C and C++.
There are many things that i have added to it but they are negligible to the many things that could be added to this code.
This is why i have implemented as much as i wanted and the rest is up to you.
With this perspective, please go through the code. Thank you.*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void swp(int *num1, int *num2)//swapping two variable's data
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void append(struct Array *arr, int x) //Adding an element at the end of the list
{
    if((*arr).length<(*arr).size)
    (*arr).A[(*arr).length++] = x;//arr->A[arr->length++] = x, nautanki!
    // debugging ke liye likhe the bhai printf("Length of the array = %d\n", (*arr).length);
}

void insert(struct Array *arr, int x, int index) //When you want to insert an element at a particular index.
{
    if(index >=0 && index < (*arr).length)
    {
        for(int i = (*arr).length; i>index; i--)//Shifting the elements to the right to make space->insert.
        (*arr).A[i] = (*arr).A[i-1];
    
        (*arr).A[index] = x;
        (*arr).length++;
    }
}

void insert(struct Array *arr, int x) 
{ // When you want to insert an element in a sorted list.
// Index is not needed here.
    if(arr->length == arr->size)
        return;
    else
    {
        int i = arr->length - 1;
        //Checking and shifting right unlike shifting only.
        while(i >= 0 && arr->A[i] > x)
        {
            arr->A[i+1] = arr->A[i];
            i--;
        }    
        arr->A[i+1] = x;
        arr->length++;
    }
    
}

int del(struct Array *arr, int index)//Delete an element at a particular index in the list
{
    if(index >=0 && index < (*arr).length)
    {
        int x = (*arr).A[index];
        for(int i = index; i<(*arr).length-1; i++)//Left shift since deleting creates gap.
            (*arr).A[i] = (*arr).A[i+1];
    
        (*arr).length--;
        return x;
    }
    //printf()
    return 0;
}

int linearSearch(struct Array arr, int x)
{
    for(int i = 0; i<arr.length; i++)//Pura list traverse
    {                                //and check each
        if(x == arr.A[i])            //element
            return i;
    }
    return -1;
}

int linearSearchTransposition(struct Array *arr, int x) // Original array mei element   
{                                                       // will keep on coming close
    for(int i = 0; i<(*arr).length; i++)                // to the start index on
    {                                                   // the basis of its requirement.
        if(x == (*arr).A[i])
        {
            swp(&arr->A[i], &arr->A[i-1]);// Debug karna zaruri with or without 
            return i-1;                   // & works the same. Interesting!
        }
    }
    return -1;
}

int linearSearchTranspositionEnhanced(struct Array *arr, int x) // Original array mei   
{                                                               //seached element will 
    for(int i = 0; i<(*arr).length; i++)                  // come to the
    {                                                // beginning for optimized search 
        if(x == (*arr).A[i])                        // next time.
        {
            swap((*arr).A[i], (*arr).A[0]);
            return 0;
        }
    }
    return -1;
}

int binarySearch(struct Array arr, int key) 
{ // //Better search algorithm than linear
    int low = 0; // but requires the list to be sorted
    int high = arr.length - 1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid - 1;
        else   
            low = mid + 1;
    }
    return -1;
}

int binarySearchRecursive(struct Array arr, int low, int high, int key)//Another way of binary search, above one was iterative.
{
    if(low <= high)
    {
        int mid = (low + high)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            return binarySearchRecursive(arr, low, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, high, key);
    }
    else
        return -1;
}

int get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array arr,int x, int index)
{
    if(index >= 0 && index < arr.length)
        arr.A[index] = x;
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i<arr.length; i++)
        if(arr.A[i]>max)    max = arr.A[i];
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i<arr.length; i++)
        if(arr.A[i] < min)    min = arr.A[i];
    return min;
}

int sumRecursive(struct Array arr, int length)
{
    if(length == 0)
        return 0;
    else
        return sumRecursive(arr, length - 1) + arr.A[length - 1];
}

double avg(struct Array arr)
{
    double sum = 0;
    for(int i = 0; i < arr.length; i++)
        sum = sum + arr.A[i];
    return (sum/arr.length);
}

void reverse(struct Array *arr)
{//A ke elements ko ulta copy in B.
    int i=0, j=0; // B ke contents A mei copy.
    int *B = (int *)malloc(arr->length*sizeof(int));
    for(i = arr->length-1, j=0; i>=0; i--, j++)
        B[j] = arr->A[i];
    for(i = 0; i<arr->length; i++)
        arr->A[i] = B[i];

    free(B);
    B = NULL;

}

void reverseEnhanced(struct Array *arr)
{ // Two pointers concept applied
    int i,j; // i saamne se, j peeche se.
    for(i=0, j=arr->length-1; i<=j; i++, j--)
        swp(&arr->A[i],&arr->A[j]);
}

void leftShift(struct Array *arr)
{ //Shift all elements of the list by one(left). 
    int i; // Right most element becomes 0 and 
    for(i = 0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[i] = 0;// the first element is lost.
}

void leftRotate(struct Array *arr)
{ // Shift all elements of the list by one(left).
// Right most element becomes the first element. 
    int i, temp = arr->A[0];
    for(i = 0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[i] = temp;
}

void rightShift(struct Array *arr) 
{ // Shift all elements of the list by one(right).
// Left most element becomes 0 and the last element is lost.
    int i;// Last element maane rightmost.
    for(i = arr->length-1; i > 0; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[i] = 0;
}

void rightRotate(struct Array *arr) 
{ // Shift all elements of the list by one(right).
// Left most element becomes last element.
    int i, temp = arr->A[arr->length-1];
    for(i = arr->length-1; i > 0; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = temp;
}

int isSorted(struct Array arr)
{
// If an anomaly is present return 0.
    for(int i = 0; i<arr.length - 1; i++)
        if(arr.A[i]>arr.A[i+1]) return 0;
    return 1;
}

void rearrange(struct Array *arr)
{ // -ve values on the left side and +ve 
//on the right side. Two pointers involved.
    int i = 0, j = arr->length - 1;
    while(i<j)
    {
        while(arr->A[i]<0)  i++;
        while(arr->A[j]>0)  j--;
        if(i<j)
            swp(&arr->A[i], &arr->A[j]);
    }
}

void merge(struct Array *a, struct Array a1, struct Array a2)
{
// arrays must be sorted, remember!
    int i=0, j=0, k=0;
    while(i<a1.length && j<a2.length)
    {
        if(a1.A[i]<a2.A[j])
            a->A[k++] = a1.A[i++];
        else  
            a->A[k++] = a2.A[j++];
    }
// ek array khatam hogaya pehle hi, to dusra pura copy paste.
// but humein nahi pata na kaun, issliye dono ka likhdo.
    for(; i<a1.length; i++)
        a->A[k++] = a1.A[i];
    for(; j<a2.length; j++)
        a->A[k++] = a2.A[j];

    a->length = k;
}

/*Set operations start here like union, intersection, difference.
Set has unique objects/elements.
Union - All elements of both the sets.
Intersection - Common elements of both the sets.
Difference - Say you want A-B, this means only those elements which are in A but not in B*/
void unionUnsorted(struct Array *a, struct Array a1, struct Array a2)
{
// Pehle 2nd list ko pura daal diye final list mei. Abh check karo
// jo elements 1st list ke 2nd mei common hai, usko nahi daalo.
    int i=0, j=0, k=0, flag = 0;
    for(; j<a2.length; j++)
        a->A[k++] = a2.A[j];
    for(i = 0; i<a1.length; i++)
    {
        for(j = 0; j<a2.length; j++)
        {
            if(a1.A[i] == a2.A[j])
                flag = 1;
        }
        if(flag == 0)
            a->A[k++] = a1.A[i];
        flag = 0;
    }

    a->length = k;
}

void unionSorted(struct Array *a, struct Array a1, struct Array a2)
{
    int i=0, j=0, k=0;
    while(i<a1.length && j<a2.length)
    {
        if(a1.A[i]<a2.A[j])
            a->A[k++] = a1.A[i++];
        else if(a1.A[i]>a2.A[j])  
            a->A[k++] = a2.A[j++];
        else
        {
            a->A[k++] = a1.A[i++];
            j++;
        }
    }
    for(; i<a1.length; i++)
        a->A[k++] = a1.A[i];
    for(; j<a2.length; j++)
        a->A[k++] = a2.A[j];

    a->length = k;
}

void intersectionUnsorted(struct Array *a, struct Array a1, struct Array a2)
{
//Ek ka element dusre mei search karte raho, same hua tabh result mei daalo.
    int i=0, j=0, k=0;
    for(i = 0; i<a1.length; i++)
    {
        for(j = 0; j<a2.length; j++)
        {
            if(a1.A[i] == a2.A[j])
                a->A[k++] = a1.A[i];;
        }
    }

    a->length = k;
}

void intersectionSorted(struct Array *a, struct Array a1, struct Array a2)
{
//Two pointers se check jisme chota usko badhao, equal pe element insert.
    int i=0, j=0, k=0;
    while(i<a1.length && j<a2.length)
    {
        if(a1.A[i]<a2.A[j])
            i++;
        else if(a1.A[i]>a2.A[j])  
            j++;
        else
        {
            a->A[k++] = a1.A[i++];
            j++;
        }
    }

    a->length = k;
}

void differenceUnsorted(struct Array *a, struct Array a1, struct Array a2)//a1 - a2
{

    int i=0, j=0, k=0, flag = 0;
    for(i = 0; i<a1.length; i++)
    {
        for(j = 0; j<a2.length; j++)
        {
            if(a1.A[i] == a2.A[j])
                flag = 1;
        }
        if(flag == 0)
            a->A[k++] = a1.A[i];
        flag = 0;
    }
    a->length = k;
}

void differenceSorted(struct Array *a, struct Array a1, struct Array a2)//a1 - a2
{
// being the smaller number is the only guarantee that the element won't be in a2.
// if element in a1 is larger than current element in a2, there might be a chance that
//this element in a1 could be in a2 later, think about it.
    int i=0, j=0, k=0;
    while(i<a1.length && j<a2.length)//1st or 2nd list can exhaust early in such cases.
    {
        if(a1.A[i]<a2.A[j])
            a->A[k++] = a1.A[i++]; 
        else if(a1.A[i]>a2.A[j])  
            j++; 
        else
        {
            i++;
            j++;
        }
    }
    for(; i<a1.length; i++) //very important case which i totally missed.
        a->A[k++] = a1.A[i];

    a->length = k;
}

void display(struct Array arr)
{
    int i;
    printf("Array Elements:\n");    
    for(i = 0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array a, b, c;
    
    printf("Enter the size of the array you want\n");
    scanf("%d",&a.size);

    a.A = (int *)malloc(a.size*sizeof(int));

    printf("Enter the number of elements you want to put in the array\n");
    scanf("%d", &a.length);

    if(a.size < a.length)
    {
        printf("Enter a valid size");
        exit(0);
    }

    printf("\nEnter the elements one by one\n");
    for(int i = 0; i<a.length; i++)
        scanf("%d", &a.A[i]);

    int ch1=1, x, index, ch;

    while(ch1 != 0)
    {
        printf("\n\n\nMenu\n");
        printf("1. Sorted or not? Check\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sum/Average\n");
        printf("6. Maximum/Minimum element\n");
        printf("7. Reverse\n");
        printf("8. Left Shift/Rotate\n");
        printf("9. Right Shift/Rotate\n");
        printf("10. Merge two arrays\n");
        printf("11. Set Operations\n");
        printf("12. Display\n");
        printf("0. Exit\n\n\n");

        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 0:
                    exit(0);
            case 1://Check if the list is sorted or not.
                    if(isSorted(a) == 1)
                        printf("\nThe array is sorted.\n");
                    else
                        printf("\nThe array is not sorted.\n");
                    break;
            case 2://Insert an element in the list.
                    printf("\nEnter the element to be inserted\n");
                    scanf("%d", &x);
                    
                    
                    if(isSorted(a) == 1)
                        insert(&a, x);
                    else
                    {
                        printf("\nEnter the index where the element is to be inserted\n");
                        scanf("%d", &index);
                        if(index == a.length)
                            append(&a, x);
                        else
                            insert(&a, x, index);
                    }

                    break;

            case 3://Delete an element.
                    printf("\nEnter the index whose element is to be deleted\n");
                    scanf("%d", &x);
                    del(&a, x);
                    break;
            
            case 4://Search an element. 
                    printf("\nEnter the element to be searched\n");
                    scanf("%d", &x);
                    /*There are 5 different seaching functions in this program.
                    Mainly two categories - Linear and Binary Search.
                    In linear search, there is the standard iterative one, then it was made slightly better using transposition,
                    or we just move the searched element at the front. These change do not affect the time complexity if only one
                    element is searched, but changes with multiple searches.
                    Then comes binary search which has logn base 2 time complexity.
                    There are two functions- one iterative and one recursive.
                    The recursive one is a tail recursion so we go with the iterative function.
                    Note - The list should be sorted for binary search to work.*/
                    if(isSorted(a) == 1)
                        printf("\nThe element is at %d\n",binarySearch(a, x));
                    else
                        printf("\nThe element is at %d\n",linearSearchTransposition(&a, x));
                    break;
            
            case 5://Summ/Average of all elements of the list.
                    printf("\n1. Sum of all elements of the list.\n");
                    printf("2. Average of all elements of the list.\n");
                    scanf("%d", &ch);
                    if(ch == 1)
                        printf("\nSum = %d\n",sumRecursive(a, a.length));
                    else   
                        printf("\nAverage = %f\n",avg(a));
                    break;

            case 6://Maximum/Minimum of all elements of the list.
                    printf("\n1. Maximum of all elements of the list.\n");
                    printf("2. Minimum of all elements of the list.\n");
                    scanf("%d", &ch);
                    if(ch == 1)
                        printf("\nThe maximum element is = %d\n",max(a));
                    else   
                        printf("\nThe maximum element is = %d\n",min(a));
                    break;

            case 7://Reverse a list.
                    reverse(&a);
                    display(a);
                    break;

            case 8://Left Shift/Rotate the list.
                    printf("\n1. Left Shift all elements of the list.\n");
                    printf("2. Left Rotate all elements of the list.\n");
                    scanf("%d", &ch);
                    if(ch == 1)
                    {
                        leftShift(&a);
                        display(a);
                    }
                    else   
                    {
                        leftRotate(&a);
                        display(a);
                    }
                    break;

            case 9://Right Shift/Rotate the list.
                    printf("\n1. Right Shift all elements of the list.\n");
                    printf("2. Right Rotate all elements of the list.\n");
                    scanf("%d", &ch);
                    if(ch == 1)
                    {
                        rightShift(&a);
                        display(a);
                    }
                    else
                    {   
                        rightRotate(&a);
                        display(a);
                    }
                    break;

            case 10://Merge two lists.
                    printf("Enter the size of the array you want\n");
                    scanf("%d",&a.size);

                    b.A = (int *)malloc(b.size*sizeof(int));

                    printf("Enter the number of elements you want to put in the array\n");
                    scanf("%d", &b.length);

                    if(b.size < b.length)
                    {
                        printf("Enter a valid size");
                        break;
                    }

                    printf("\nEnter the elements one by one\n");
                    for(int i = 0; i<b.length; i++)
                        scanf("%d", &b.A[i]);

                    c.A = (int *)malloc((a.size + b.size)*sizeof(int));

                    merge(&c, a, b);
                    display(c);

                    free(b.A);
                    free(c.A);
                    break;

            case 11://Set Operations on lists.
                    printf("Enter the size of the array you want\n");
                    scanf("%d",&a.size);

                    b.A = (int *)malloc(b.size*sizeof(int));

                    printf("Enter the number of elements you want to put in the array\n");
                    scanf("%d", &b.length);

                    if(b.size < b.length)
                    {
                        printf("Enter a valid size");
                        break;
                    }

                    printf("\nEnter the elements one by one\n");
                    for(int i = 0; i<b.length; i++)
                        scanf("%d", &b.A[i]);

                    c.A = (int *)malloc((a.size + b.size)*sizeof(int));

                    printf("\n1. Union of the sets\n");
                    printf("2. Intersection of the sets\n");
                    printf("3. Difference of the sets\n");
                    scanf("%d", &ch);
                    if(ch == 1)
                    {
                        if(isSorted(a) == 1 && isSorted(b) == 1)
                            unionSorted(&c, a, b);
                        else
                            unionUnsorted(&c, a, b);
                    }
                    else if(ch == 2)
                    {
                        if(isSorted(a) == 1 && isSorted(b) == 1)
                            intersectionSorted(&c, a, b);
                        else
                            intersectionUnsorted(&c, a, b);
                    }
                    else
                    {
                        if(isSorted(a) == 1 && isSorted(b) == 1)
                            differenceSorted(&c, a, b);
                        else
                            differenceUnsorted(&c, a, b);
                    }
                    display(c);

                    free(b.A);
                    free(c.A);
                    break;

            case 12://Display list elements.
                    display(a);
                    break;
            default:
                    printf("\n---Wrong Input. Please follow the menu properly---\n");

        }
    }
    

    free(a.A);
    return 0;
}