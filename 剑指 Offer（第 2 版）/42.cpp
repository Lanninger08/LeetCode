// 剑指 Offer 42. 连续子数组的最大和
// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int pre = 0;
        for(int i=0;i<nums.size();++i){
            pre = max(pre+nums[i], nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};