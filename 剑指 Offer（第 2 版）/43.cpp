// 剑指 Offer 43. 1～n 整数中 1 出现的次数
// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/


class Solution {
public:
    // 数学规律
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

    // 找规律dp
    /* 使用动态规划，从低位遍历到高位
       设 dp[i] 为第一至第i位的1的个数，从 dp[i-1] 到 dp[i] 的状态转移分3种情况
       1. 第i位为0 dp[i]=dp[i-1]
       2. 第i位为1 dp[i] 包含了1到(i-1)位 1的个数 以及 最高位中1的个数
            以 177为例 
               - 1到(i-1)位 1的个数：(0-99)个位十位1的个数 + (100-177)个位十位1的个数
                    即 num(99) + dp[i-1]
               - 最高位中1的个数：(100-177) -> 77+1个，即 n % (10^(i-1)) + 1
          dp[i] = num(99) + dp[i-1] + (n % (10^(i-1)) + 1)
       3. 第i位为其他
            以877为例
               - 1到(i-1)位 1的个数：(0-799)个位十位1的个数 + (800-877)个位十位1的个数
                    即 8 * num(99) + dp[i-1]
               - 最高位中1的个数：(100-199) -> 100个，即 10^(i-1)
          dp[i] = 8 * num(99) + dp[i-1] + (10^(i-1)) 
    */
};

// 通用的数位dp

#include<cstring>
using namespace std;

/*
从最高位开始递归计算，用pos,count,limit表示计算到第pos位时，已经出现了count个1，
之后的数字有无限制（能否取遍0~9）。
*/
class Solution {
public:
    int digit[11];
    int dp[11][11];
    int dfs(int pos, int count, bool limit){
        // 递归边界，既然是按位枚举，最低位是1，那么pos==0说明这个数枚举完了
        if(pos == 0){
            return count;
        }
        // 非限制状态的同一层数字情况(相当于p层)，且count所记录下的数字相同，可以直接返回结果（记忆化）
        if(!limit && dp[pos][count] != -1){
            return dp[pos][count];
        }
        // 每一层都要刷新res
        int res = 0;
        // 如果处于限制状态则该位最多取 digit[p] 否则 0-9
        int max = limit?digit[pos]:9;
        // 对当前pos的数字进行枚举
        for(int i = 0; i <= max; ++i){
            if(i == 1){
                res += dfs(pos-1, count + 1, limit && (i == max));
            }else{
               res += dfs(pos-1, count, limit && (i == max)); 
            }
        }
        if(!limit){
            dp[pos][count] = res;
        }
        return res;
    }
    int solve(int n){
        // 初始化-1
        memset(dp, -1, sizeof(dp));
        int pos = 0;
        // 实现对n的从最低位到最高位数位拆分
        while(n){
            digit[++pos] = n%10;
            n /= 10;
        }
        // 从最高位开始
        return dfs(pos, 0, true);
    }
    int countDigitOne(int n) {
        if(n <= 0){
            return 0;
        }
        return solve(n);
    }
};