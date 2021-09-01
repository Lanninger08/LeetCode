// 剑指 Offer 65. 不用加减乘除做加法
// https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/

class Solution {
public:
    int add(int a, int b) {
        // 无进位和 与 异或运算 规律相同，进位 和 与运算 规律相同（并需左移一位）
        while(b) {
            int carry = (unsigned int)(a&b)<<1; //C++中负数不支持左移位，因为结果是不定的
            a ^= b;
            b = carry;
        }
        return a;
    }
};