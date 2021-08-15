// 剑指 Offer 51. 数组中的逆序对
// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size()-1);
    }
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if(l>=r) return 0;
        int mid = (l+r)/2;
        int cnt = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid+1, r);
        int i=l, j=mid+1;
        for(int k=l; k<=r; k++) tmp[k] = nums[k];
        for(int k=l; k<=r; k++){
            if (i==mid+1) nums[k] = tmp[j++];
            else if (j==r+1 || tmp[i]<=tmp[j]) nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                cnt += mid-i+1;
            }
        }
        return cnt;
    }
};