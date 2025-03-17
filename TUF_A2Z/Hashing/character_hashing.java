import java.util.Scanner;
public class character_hashing {
    
    public static void main(String args[])
    {
        try( Scanner sc = new Scanner(System.in) )
        {
            String input = sc.next();
            int hash[] = new int[26];//for pura, take 256
            int i;
            char c;

            for( i = 0; i < input.length(); i++ )
            {
                c = input.charAt(i);
                hash[c-'a']++;//-'a' hat jaega for 256
            }

            i = sc.nextInt();
            while(i != 0)
            {
                c = sc.next().charAt(0);
                System.out.println(hash[c-'a']);//-'a' hat jaega for 256
                i--;
            }   
        }
    }
}
