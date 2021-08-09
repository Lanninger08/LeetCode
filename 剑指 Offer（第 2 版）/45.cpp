// 剑指 Offer 45. 把数组排成最小的数
// https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // 快排
    string minNumber1(vector<int>& nums) {
        vector<string> strs;
        for(int i=0;i<nums.size();++i){
            strs.push_back(to_string(nums[i]));
        }
        quick_sort(strs, 0, strs.size()-1);
        string ans;
        for(string s: strs){
            ans.append(s);
        }
        return ans;
    }

    void quick_sort(vector<string>& strs, int left, int right){
        if(left >= right) return;
        int i=left, j=right;
        while(i<j){
            while(strs[j]+strs[left]>=strs[left]+strs[j] && i<j) j--;
            while(strs[i]+strs[left]<=strs[left]+strs[i] && i<j) i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i],strs[left]);
        quick_sort(strs, left, i-1);
        quick_sort(strs, i+1, right);
    }

    // 内置函数法
    string minNumber2(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });
        for(int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};