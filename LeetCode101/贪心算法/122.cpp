#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size()==0) return 0;
    int min = prices[0], res = 0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>min){
            res += (prices[i]-min);
        }
        min = prices[i];
    }
    return res;
}

// 官方答案 更优雅
int leetcode_sol_122(vector<int>& prices) {   
    int ans = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
        ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
}