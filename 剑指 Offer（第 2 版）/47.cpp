// 剑指 Offer 47. 礼物的最大价值
// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1));
        for (int i=1; i<=row; ++i){
            for (int j=1; j<=col; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[row][col];
    }
};