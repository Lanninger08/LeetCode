// 剑指 Offer 14- I. 剪绳子I
// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/

/**
 * 数学推导总体分为两步：① 当所有绳段长度相等时，乘积最大。② 最优的绳段长度为 3。
 * 如果 n<=3 应该不切分，但由于题目要求必须剪成m>1段，因此必须剪出一段长度为1的绳子，另一根长度n-1
 * 如果 n>3 求对3的余数，余数0，直接3相乘；余数1，换成一个4；余数2，就多乘一个2 
 * 
 * 动态规划：
 * 用一个dp数组记录从0到n长度的绳子剪掉后的最大乘积，初始化dp[2] = 1
 * j从2开始，因为剪掉长度1对结果无增益
 * 剪了第一段后，剩下(i - j)长度可以剪也可以不剪。如果不剪的话长度乘积即为j * (i - j)；
 * 如果剪的话长度乘积即为j * dp[i - j]。取两者最大值max(j * (i - j), j * dp[i - j])
 * 转移方程：dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]))
 */
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int cuttingRope1(int n) {
        if(n<=3){
            return n-1;
        }else{
            int a = n/3;
            int b = n%3;
            if(b==0){
                return pow(3, a);
            }else if(b==1){
                return pow(3, a-1)*4;
            }else{
                return pow(3, a)*2;
            }
        }
    }
    int cuttingRope2(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for(int i=3;i<=n;++i){
            for(int j=2;j<i;++j){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};