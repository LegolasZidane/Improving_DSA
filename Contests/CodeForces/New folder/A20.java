import java.util.Scanner;
class A20
{
    public static void main(String args[])
    {
        try(Scanner sc = new Scanner(System.in))
        {
            int t = sc.nextInt();
            for( int i = 1 ; i <= t; i++ )
            {
                int n = sc.nextInt();
                int k = sc.nextInt();
                int count = 1;
                
                if( n%k != 0 )
                {
                    n = n-k;
                    k--;
                }
                else
                {
                    System.out.println(count);
                    continue;
                }
                while( n != 0 )
                {
                    count++;
                    while( k != 0 && n%k > 0 )
                        k = k - 2;
                    if( k == 0 )
                        k = 1;
                    n = n%k;
                }
                System.out.println(count);
            }
        }
    }
}