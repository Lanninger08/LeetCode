// 剑指 Offer 48. 最长不含重复字符的子字符串
// https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/

#include<string>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 动态规划 + 哈希表
    int lengthOfLongestSubstring1(string s) {
        int max_len = 0, tmp_len = 0;
        unordered_map<char,int> mp;
        int index;
        for(int i=0; i<s.size(); ++i){
            // 获取 s[i] 索引
            if(mp.find(s[i]) == mp.end()) index = -1;
            else index = mp[s[i]];
            // 更新 map
            mp[s[i]] = i;
            // 出现过的字符在tmp字符串起始位置之前，说明不影响结果，直接tmp+1就行
            // 如果出现过的字符在tmp字符串内，就要截断了，tmp字符串为两个相同字符之间的字符串
            tmp_len = tmp_len < i-index ? tmp_len+1 : i-index;
            max_len = max(max_len, tmp_len);
        }
        return max_len;
    }

    // 滑动窗口
    int lengthOfLongestSubstring2(string s) {
        int max_len = 0, left = 0, pos = 0;
        // 字符的 ASCII 码范围为 0 ~ 127，用128其实就行
        vector<bool> used(256, false);
        while(pos < s.size()){
            // 当窗口最右边的元素在窗口内存在，就移动left直到没有重复元素
            while(used[s[pos]]) used[s[left++]] = false;
            // 实时记录最长的子字符串
            max_len = max(max_len, pos-left+1);
            used[s[pos++]] = true;
        }
        return max_len;
    }
};