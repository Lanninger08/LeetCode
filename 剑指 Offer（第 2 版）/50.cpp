// 剑指 Offer 50. 第一个只出现一次的字符
// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/

#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // method1 遍历两次数组 哈希表存出现次数
    char firstUniqChar(string s) {
        unordered_map<int, int> freq;
        for (char c: s) {
            freq[c]++;
        }
        for (char c: s) {
            if(freq[c]==1){
                return c;
            }
        }
        return ' ';
    }

    // method2 有序哈希表，保持插入顺序，遍历字符串一次，哈希表一次
    char firstUniqChar(string s) {
        vector<char> keys;
        unordered_map<char, int> freq;
        for (char c: s) {
            if(freq[c]==0) keys.push_back(c);
            freq[c]++;
        }
        for (char c: keys) {
            if (freq[c] == 1) return c;
        }
        return ' ';
    }
};