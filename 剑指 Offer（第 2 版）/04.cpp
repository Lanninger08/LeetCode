// 剑指 Offer 04. 二维数组中的查找
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

/*
从右上角开始走，利用这个顺序关系可以在O(m+n)的复杂度下解决这个题：
    如果当前位置元素比target小，则row++
    如果当前位置元素比target大，则col--
    如果相等，返回true
    如果越界了还没找到，说明不存在，返回false
*/

#include<vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 注意边界条件判断
        if(matrix.empty()||matrix[0].empty()){
            return false;
        }
        int m = matrix.size();
        int col = matrix[0].size()-1;
        int row = 0;
        while(row<m && col>=0){
            if(matrix[row][col]<target){
                row++;
            }else if(matrix[row][col]>target){
                col--;
            }else{
                return true;
            }
        }
        return false;
    }
};