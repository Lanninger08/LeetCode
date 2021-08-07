// 剑指 Offer 44. 数字序列中某一位的数字
// https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/

#include<string>
using namespace std;

class Solution {
public:
    // n 代表数位，num 代表数字，digit 为位数（2位，3位），start 为每digit位数的起始数字
    int findNthDigit(int n) {
        long digit = 1;
        long start = 1;
        long count = 9;
        // 1. 确定所求数位的所在数字的位数
        while (n > count) {
            n -= count;
            start *= 10;
            digit++;
            count = 9 * start * digit;
        }
        // 2. 确定所求数位所在的数字
        long num = start + (n-1) / digit;
        // 3. 确定所求数位在 num 的哪一数位
        string s = to_string(num);
        return s[(n-1)%digit] -'0';
    }
};