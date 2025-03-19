public class ValidArray {
    static int isThereValidArray(int n, int s) {
        
        int i = n, j = 0;

        int sum1 = 0, sum2 = 0, sum = i*(i+1)/2;
        if( sum == s )
            return 1;

        while( sum < s )
        {
            i++;
            sum1 = i*(i+1)/2;
            j++;
            sum2 = j*(j+1)/2;

            sum = sum1 - sum2;

            if( sum == s )
                return 1;
        }
        return 0;
    }
}