public class beautifulArray{
    static int perfectArray(int n, int []a) {
        
        int i, flag1 = 0, flag2 = 0;

        for( i = 0; i < n; i++ )
        {
            if( 2*i + 2 < n )
            {
                if( a[i]%a[2*i+2] != 0 )
                    flag1 = 1;
            }
            
            if( 2*i + 1 < n )
            {
                if( a[i]%a[2*i+1] != 0 )
                    flag2 = 1;
            }

            if( flag1 == 1 || flag2 == 1 )
                return 0;
        }
        return 1;
    }
}
