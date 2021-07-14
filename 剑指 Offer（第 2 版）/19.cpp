// 剑指 Offer 19. 正则表达式匹配
// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/

/**
 * 假设主串为A（长度n），模式串为B（长度m）
 * B的最后一个字符串有三种可能：正常字符 . *
 *      1. 如果是正常字符，比较 A[n-1] 是否等于 B[m-1]。相等则往前比较 A[0...n-2] B[0...m-2]
 *      2. 如果是 . 直接比较 A[0...n-2] B[0...m-2]
 *      3. 如果是 * 表示 B[m-2]=c 重复0次或多次
 *          1) A[n-1] 是0个c，B的最后两个字符废了，比较 A[0...n-1] B[0...m-3]是否匹配
 *          2) A[n-1] 是多个c的最后一个，（A[n-1]=c 或 c=.）所以A匹配完后往前挪一位 比较 A[0...n-2] B[0...m-1]
 * 
 * 转移方程
 * dp[i][j]表示 A的前i个和B的前j个是否匹配
 *   对于情况1和2，都有 dp[i][j] = dp[i-1][j-1]
 *   对于情况3，dp[i][j]=dp[i][j-2] 或 dp[i][j]=dp[i-1][j]
 */

#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length()+1;
        int m = p.length()+1;
        bool dp[n][m];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(j==0){
                    // 空正则
                    dp[i][j] = i==0;
                }else{
                    if(p[j-1] != '*'){
                        // 情况1&2
                        if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='.')){
                            dp[i][j] = dp[i-1][j-1];
                        }
                    } else {
                        // 3.1 （不太理解 为什么不用判断A[n-1]!=B[m-2]）
                        if(j>=2){
                            dp[i][j] = dp[i][j] || dp[i][j-2];
                        }
                        if(i>=1 && j>=2 && (s[i-1]==p[j-2] || p[j-2]=='.')){
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};