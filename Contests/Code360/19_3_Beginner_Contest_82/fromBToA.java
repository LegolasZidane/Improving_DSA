public class fromBToA {

    static int gcd( int a, int b)
    {
        while( a>0 && b>0 )
                {
                    if( a > b )
                        a = a%b;
                    else
                        b = b%a;
                }
        if( a == 0)
            return b;
        else 
            return a;
    }
    static int reachBFromA(int a, int b) {
        
        if( (a-b)/gcd(a,b) != (a-b) )
            return 1;
        else
            return 0;

    }
}