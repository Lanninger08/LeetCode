// 剑指 Offer 53 - I. 在排序数组中查找数字 I
// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int count=0;
        while(left<right) {
            int mid = (left+right)/2;
            if(nums[mid]>=target) right = mid;
            else left = mid+1;
        }
        while(left<nums.size()&&nums[left++]==target) count++;
        return count;
    }
};

// 剑指 Offer 53 - II. 0～n-1中缺失的数字
// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/

class Solution {
public:
// 只要比较数组下标和该下标对应的值即可
    int missingNumber(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        // <= 排除缺失0和缺失最后一项两个特殊情况
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==mid) left=mid+1;
            else right = mid-1;
        }
        return left;
    }
};