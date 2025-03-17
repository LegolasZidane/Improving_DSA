import java.util.Scanner;
class hash
{
    public static void main(String args[])
    {
        try(Scanner sc = new Scanner(System.in))
        {
            int size = sc.nextInt();
            int a[] = new int[size], hash[] = new int[13];
            int i;


            for( i = 0; i < size; i++ )
                a[i] = sc.nextInt();

            for( i = 0; i < size; i++ )
                hash[a[i]]++;
            
            int q, x;
            q = sc.nextInt();
            while(q != 0)
            {
                x = sc.nextInt();
                System.out.println(hash[x]);
                q--;
            }
        }
    }
}