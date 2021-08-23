// 剑指 Offer 58 - I. 翻转单词顺序
// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/

#include<string>
using namespace std;

class Solution {
public:
    // 双指针
    string reverseWords(string s) {
        string res;
        if(s.size()==0) return res;
        int right = s.size()-1;
        while(right>=0) {
            // 从后往前找到第一个字符
            while(right>=0 && s[right]==' ') right--;
            if(right<0) break;

            // 从后往前找到第一个空格
            int left = right;
            while(left>=0 && s[left]!=' ') left--;

            res += s.substr(left+1, right-left);
            res += ' ';
            right = left;
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};