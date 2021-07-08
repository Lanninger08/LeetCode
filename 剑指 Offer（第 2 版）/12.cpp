// 剑指 Offer 12. 矩阵中的路径
// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        // 对于每一个格子都试一下
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    // i,j 代表坐标  k代表word的index
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        // 越界或不匹配 剪枝
        if(i >= board.size() || j >= board[0].size() || i<0 || j<0 || board[i][j] != word[k]){
            return false;
        }
        // 完全匹配
        if(k == word.size()-1){
            return true;
        }
        // 防止重复匹配
        board[i][j] = '\0';
        bool result = dfs(board, word, i-1, j, k+1) || dfs(board, word, i+1, j, k+1) || dfs(board, word, i, j-1, k+1) || dfs(board, word, i, j+1, k+1);
        board[i][j] = word[k];
        return result;
    }
};