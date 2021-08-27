// 剑指 Offer 60. n个骰子的点数
// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    // 正向动态规划
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0/6.0);
        for(int i=2;i<=n;++i) {
            // i个骰子所有的可能值 n-6n 个数5n+1
            vector<double> tmp (5*i+1, 0);
            for(int j=0; j<dp.size(); ++j){
                for(int k=0; k<6; ++k){
                    // k代表第i歌骰子掷出的值（0-5是因为下标问题）
                    // 加上dp数组值与1/6的乘积，1/6是第i个骰子投出某个值的概率
                    tmp[j+k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};