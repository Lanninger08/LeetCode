// 剑指 Offer 61. 扑克牌中的顺子
// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/

#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // 集合 Set + 遍历 时间复杂度O(n) 空间复杂度O(n)
    // set本身是有序的，不用单独求最大最小 如果是无序的，就在遍历的时候用两个辅助变量记录就行
    bool isStraight1(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()) return false;
            if(nums[i]) s.insert(nums[i]);
        }
        return (*s.rbegin() - *s.begin())<5;
    }
    // 排序+遍历 时间复杂度O(nlogn) 空间复杂度O(1)
    bool isStraight2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // 记录大小王个数
        int joker=0;
        for(int i=0;i<4;++i){
            if(nums[i]==0) joker++;
            // 要用else
            else if(nums[i]==nums[i+1]) return false;
        }
        return (nums[4]-nums[joker])<5;
    }
};