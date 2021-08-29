// 剑指 Offer 62. 圆圈中最后剩下的数字
// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/


// dp[i]=(dp[i−1]+m)%i
// 通过f(1) = 0 反推

class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i=2;i<=n;i++) {
            ans = (ans+m)%i;
        }
        return ans;
    }
};