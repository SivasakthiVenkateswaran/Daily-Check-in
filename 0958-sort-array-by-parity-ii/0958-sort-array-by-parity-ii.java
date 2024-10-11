class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        if(nums.length<2)
        {
            return nums;
        }
        int temp;
        int num[]=new int[nums.length];
        int even=0,odd=1;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]%2==0)
            {
                num[even]=nums[i];
                even=even+2;
            }
            else
            {
                num[odd]=nums[i];
                odd=odd+2;
            }

        }
        return num;
    }
}