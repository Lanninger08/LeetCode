// 剑指 Offer 66. 构建乘积数组
// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len == 0) return {};
        int tmp = 1;
        vector<int> b(len, 1);
        for(int i=1; i<len; i++) {
            b[i] = b[i-1] * a[i-1];  // 下三角
        }
        for(int i=len-2; i>=0; i--) {
            tmp *= a[i+1];  // 上三角
            b[i] *= tmp;
        }
        return b;
    }
};