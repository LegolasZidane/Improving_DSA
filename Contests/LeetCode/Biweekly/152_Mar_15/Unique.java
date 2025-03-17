class Unique {
    public int totalNumbers(int[] digits) {
    
        int i = 0, j, k, n = digits.length, num1, num2, count = 0;
        Set<Integer> s = new HashSet<Integer>();

        while( i != n )
            {
                if( digits[i] != 0 )
                {
                    j = ( i + 1 )%n;
                    while( j != i )
                        {
                            k = ( j + 1 )%n;
                            while( k != i )
                                {
                                    num1 = digits[i]*100 + digits[j]*10 + digits[k];
                                    num2 = digits[i]*100 + digits[k]*10 + digits[j];
                                    if( num1%2 == 0 )
                                        s.add(num1);
                                    if( num2%2 == 0 )
                                        s.add(num2);
                                    k = ( k + 1 )%n;
                                }
                            j = ( j + 1 )%n;
                        }
                }
                i++;
            }
        for( int l:s)
            count++;
        return count;
    }
}