// 剑指 Offer 49. 丑数
// https://leetcode-cn.com/problems/chou-shu-lcof/

#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    // 最小堆
    int nthUglyNumber(int n) {
        vector<int> factors={2, 3, 5};
        unordered_set<long> counted;
        priority_queue<long, vector<long>, greater<long>> heap;
        counted.insert(1L);
        heap.push(1L);
        int ugly_num = 0;
        for (int i=0; i<n; ++i){
            long cur = heap.top();
            heap.pop();
            ugly_num = (int) cur;
            for (int factor: factors){
                long next = cur*factor;
                if(!counted.count(next)) {
                    counted.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly_num;        
    }

    // 动态规划
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int pointer2=1, pointer3=1, pointer5=1;
        for(int i=2; i<=n; ++i){
            int num2 = dp[pointer2]*2, num3 = dp[pointer3]*3, num5 = dp[pointer5]*5;
            // 产生的新的丑数由原来的丑数*2 *3 *5得到
            dp[i] = min(min(num2, num3), num5);
            // 防止重复
            if (dp[i] == num2) pointer2++;
            if (dp[i] == num3) pointer3++;
            if (dp[i] == num5) pointer5++;
        }
        return dp[n];
    }
};