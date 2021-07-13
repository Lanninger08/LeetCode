// 剑指 Offer 16. 数值的整数次方
// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/

/**
 * 当 x=0 时，直接返回0（避免1/x的影响）
 * 当 n<0 时，要把问题转化为 n>=0 的范围内，x=1/x，n=-n
 * 二分法快速幂：n=0时跳出循环
 *    1. n%2 == 1   ans*=x
 *    2. x*=x
 *    3. n/=2
 */

using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if(!x){
            return 0;
        }
        double ans = 1;
        if(n<0){
            x = 1/x;
            n = -n;
        }
        while(n){
            if(n&1 == 1){
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};