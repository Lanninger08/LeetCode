// 剑指 Offer 14- II. 剪绳子II
// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/


#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    // 循环求余
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int p = 1000000007;
        long long result = 1L;
        while(n>4){
            result = (result*3)%p;
            n -= 3;
        }
        return (int)((result*n)%p);
    }
};