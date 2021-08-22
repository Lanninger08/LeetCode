// 剑指 Offer 57. 和为s的两个数字
// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<high) {
            int sum = nums[low]+nums[high];
            if(sum<target) ++low;
            else if(sum>target) --high;
            else return vector<int> {nums[low], nums[high]};
        }
        return {};
    }
};

// 剑指 Offer 57 - II. 和为s的连续正数序列
// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/

// 滑动窗口
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1; // 滑动窗口的左边界
        int j = 1; // 滑动窗口的右边界
        int sum = 0; // 滑动窗口中数字的和
        vector<vector<int>> res;

        // 5最大可能是2+3，不可能是3+4
        while (i <= target / 2) {
            if (sum < target) {
                sum += j;
                j++;
            } else if (sum > target) {
                sum -= i;
                i++;
            } else {
                // 记录结果
                vector<int> arr;
                for (int k = i; k < j; k++) {
                    arr.push_back(k);
                }
                res.push_back(arr);
                // 左边界向右移动
                sum -= i;
                i++;
            }
        }
        return res;
    }
};