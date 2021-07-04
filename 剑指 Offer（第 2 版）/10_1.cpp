// 剑指 Offer 10- I. 斐波那契数列
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

#include<vector>
using namespace std;

class Solution {
public:

    // 一开始写的复杂度很高的动态规划
    int fib1(int n) {
        if(n==0){
            return 0;
        }
        vector<int> fibonacci(n+1);
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        for(int i=2;i<=n;i++){
            fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%1000000007;
        }
        return fibonacci[n];
    }

    // 空间优化到 O(1) 另：++i比i++快好多
    int fib(int n) {
        if(n==0){
            return 0;
        }
        int a = 0;
        int b = 1;
        int sum = 0;
        for(int i=0;i<n;++i){
            sum = (a+b)%1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};