// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

// 头尾指针

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int index_left=0;
        int index_right=nums.size()-1;

        while(index_left<index_right){
            // 找到左边的偶数 注意要用if+continue，直接用while会有问题（没办法回到最外面一层判断）
            if((nums[index_left]&1)==1){
                ++index_left;
                continue;
            }
            if((nums[index_right]&1)==0){
                --index_right;
                continue;
            }
            int tmp = nums[index_left];
            nums[index_left] = nums[index_right];
            nums[index_right] = tmp;
            // 优化
            ++index_left;
            --index_right;
        }
        return nums;
    }
};