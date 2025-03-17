import java.util.*;

class arrays
{
    public static void reverse(int arr[], int start, int end)
    {
        int temp;
        while( start < end )
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static int largestElement(int arr[])
    {// smallest bhi aise hi
        int max = Integer.MIN_VALUE, i;
        for( i = 0 ; i < arr.length; i++ )
            if( arr[i] > max )  max = arr[i];

        return max;
    }

    public static int secondLargest(int arr[])
    {//second smallest bhi aise hi
        int max = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, i;
        for( i = 0 ; i < arr.length; i++ )
        {
            if( arr[i] > max )
            {
                max2 = max;
                max = arr[i];
            }
            else if( arr[i] < max && arr[i] > max2 )
                max2 = arr[i];
        }
        return max2;
    }

    public static boolean isSorted(int arr[])
    {
        int i;
        for( i = 0; i < arr.length - 1; i++ )
        {
            if( arr[i] <= arr[i+1] )
            {
            }
            else
                return false;
        }
        return true;
    }

    public static void leftRotate(int arr[], int k)
    {//right rotate bhi aise hi
        reverse(arr, 0, k%arr.length - 1);
        reverse(arr, k%arr.length, arr.length-1);
        reverse(arr, 0, arr.length-1);
    }


    public static void display(int arr[])
    {
        for( int i:arr)
            System.out.print(i + " ");
    }

    public static void main(String args[])
    {
        int arr[] = {1,2,3,4,5,6,7};
        //System.out.println("Largest element is ="+largestElement(arr));
        //System.out.println("Second largest element is ="+secondLargest(arr));
        //System.out.println(isSorted(arr));
        /*reverse(arr);
        display(arr);*/
        /*leftRotate(arr, 3);
        display(arr);*/
    }
}