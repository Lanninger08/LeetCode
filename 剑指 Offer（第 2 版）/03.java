class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i=0; i<nums.length; ++i) {
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]) return nums[i];
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }
}