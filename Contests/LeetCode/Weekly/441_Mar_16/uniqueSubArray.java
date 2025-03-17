class uniqueSubArray {
    public int maxSum(int[] nums) {

        Arrays.sort(nums);
        int i = 0 , j = 0 , sum = 0 , n = nums.length;
        if( nums[n-1] <= 0)
            return nums[n-1];
        while( i < n && nums[i] <= 0 )i++;

        sum = nums[i];
        for( j = i+1; j < n ; j++ )
            {
                if( nums[j] == nums[i])
                {
                        while( i < n && nums[i] == nums[j] )i++;
                        j = i - 1;
                }
                else
                    i++;
                if( i < n)
                    sum += nums[i];
            }
        return sum;
    }
}