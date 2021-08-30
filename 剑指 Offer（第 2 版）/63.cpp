// 剑指 Offer 63. 股票的最大利润
// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        int min_val = prices[0];
        for(int i=1; i<prices.size(); ++i) {
            ans = max(ans, prices[i]-min_val);
            if(prices[i]<min_val) min_val = prices[i];
        }
        return ans;
    }
};