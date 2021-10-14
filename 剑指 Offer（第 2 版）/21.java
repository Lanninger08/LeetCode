class Solution {
    public int[] exchange(int[] nums) {
        int left = 0;
        int right = nums.length-1;
        while(left<right){
            while(left<nums.length && nums[left]%2==1) left++;
            while(right>=0 && nums[right]%2==0) right--;
            if(left<right){
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return nums;
    }
}