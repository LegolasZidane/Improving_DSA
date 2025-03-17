import java.util.HashMap;
import java.util.Scanner;
public class asli_hashing {
    
    public static void main(String args[])
    {
        try(Scanner sc = new Scanner(System.in))
        {
            int size = sc.nextInt();
            int a[] = new int[size];
            HashMap<Integer, Integer> hash = new HashMap<>();
            int i,x;

            for( i = 0; i < size; i++ )
            {
                a[i] = sc.nextInt();
                if( hash.get(a[i]) == null )
                    hash.put(a[i], 1);
                else
                    hash.put(a[i], hash.get(a[i])+1);
            }

            i = sc.nextInt();

            while( i != 0 )
            {
                x = sc.nextInt();
                System.out.println(hash.get(x));
                i--;
            }

        }
    }

}
