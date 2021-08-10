// 剑指 Offer 46. 把数字翻译成字符串
// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/

#include<string>
using namespace std;

class Solution {
public:
    // 动态规划
    int translateNum1(int num) {
        string src = to_string(num);
        if(src.size()<2){
            return src.size();
        }
        int dp[src.size()+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=src.size();++i){
            dp[i] = dp[i-1];
            if(src.substr(i-2,2)<="25" && src.substr(i-2,2)>="10"){
                dp[i] += dp[i-2];
            }
        }
        return dp[src.size()];
    }
    // 动态规划 空间优化
    int translateNum2(int num) {
        string src = to_string(num);
        int dp2 = 1, dp1 = 1;
        for(int i=2; i<=src.size(); ++i){
            int dpi = (src.substr(i-2,2)<="25" && src.substr(i-2,2)>="10")?dp1+dp2:dp1;
            dp2=dp1;
            dp1=dpi;
        }
        return dp1;
    }
    // 数字求余 空间优化（从O(n)（字符串）到O(1)）
    int translateNum3(int num) {
        int dp2 = 1, dp1 = 1, shiwei, gewei = num % 10;
        while(num!=0){
            num /= 10;
            shiwei = num%10;
            int tmp = 10*shiwei+gewei;
            int dpi = (tmp<=25 && tmp>=10)?dp1+dp2:dp1;
            dp2=dp1;
            dp1=dpi;
            gewei = shiwei;
        }
        return dp1;
    }
};