// 剑指 Offer 03. 数组中重复的数字
// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

#include<vector>
#include<set>
using namespace std;

class Solution {
public:

    // 用数组存数字出现次数
    int findRepeatNumber1(vector<int>& nums) {
        vector<int> cnt(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(cnt[nums[i]]>0){
                return nums[i];
            }
            cnt[nums[i]]++;
        }
        return -1;
    }

    // 用set存
    int findRepeatNumber2(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()){
                return nums[i];
            }
            s.insert(nums[i]);
        }
        return -1;
    }

    // 在原数组改动 时间O(n) 空间O(1)
    // 交换 num[i] 和 num[num[i]] 直到nums[i]=i
    int findRepeatNumber3(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};