// 剑指 Offer 15. 二进制中1的个数
// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/

#include<stdint.h>
using namespace std;

class Solution {
public:
    // 方法一：逐位判断 n&1
    int hammingWeight1(uint32_t n) {
        int cnt = 0;
        while(n!=0){
            if(n&1){
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
    // 方法二：巧用 n & (n−1)
    int hammingWeight2(uint32_t n) {
        int cnt = 0;
        while(n!=0){
            cnt++;
            n &= n-1;
        }
        return cnt;
    }
};