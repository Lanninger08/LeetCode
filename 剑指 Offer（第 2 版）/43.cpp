// 剑指 Offer 43. 1～n 整数中 1 出现的次数
// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/


class Solution {
public:
    int countDigitOne(int n) {
        long digit=1;
        int ans=0;
        int high = n/10, cur = n%10, low=0;
        while(high!=0 || cur!=0){
            // cur=0, 个数由高位决定
            if(cur == 0) ans += high * digit;
            // cur=1, 个数由高位和低位决定
            else if(cur == 1) ans += high * digit + low +1;
            // 其他, 个数由高位决定
            else ans += (high+1) * digit;
            // 更新变量
            low += cur * digit;
            cur = high%10;
            high /= 10;
            digit *= 10;
        }
        return ans;
    }
};