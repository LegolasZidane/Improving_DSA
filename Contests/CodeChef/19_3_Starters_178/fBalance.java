import java.util.*;

class fBalance
{
    public static void main(String args[])
    {
        
        try( Scanner sc = new Scanner(System.in))
        {
            
            int f1 = sc.nextInt();
            int p1 = sc.nextInt();
            int f2 = sc.nextInt();
            int p2 = sc.nextInt();
            int first = Math.abs(f1-p1);
            int second = Math.abs(f2-p2);
            
            if( first < second )
                System.out.println("First");
            else if( second < first )
                System.out.println("Second");
            else
                System.out.println("Both");

        }
        
    }
}
