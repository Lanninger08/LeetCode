// 剑指 Offer 29. 顺时针打印矩阵
// https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/

// 考虑左上右下四个边界，时间复杂度O(mn) 空间复杂度O(1)

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int left=0, right=matrix[0].size()-1, top=0, bottom=matrix.size()-1, x=0;
        vector<int> res;
        while(true){
            // left -> right
            for(int i=left;i<=right;++i) res.push_back(matrix[top][i]);
            if(++top > bottom) break;
            // top -> bottom
            for(int i=top;i<=bottom;++i) res.push_back(matrix[i][right]);
            if(--right < left) break;
            // right -> left
            for(int i=right;i>=left;--i) res.push_back(matrix[bottom][i]);
            if(--bottom < top) break;
            // bottom -> top
            for(int i=bottom;i>=top;--i) res.push_back(matrix[i][left]);
            if(++left > right) break; 
        }
        return res;        
    }
};