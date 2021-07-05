// 剑指 Offer 11. 旋转数组的最小数字
// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==0){
            return -1;
        }
        int left = 0;
        int right = numbers.size()-1;
        int mid;
        while(left<right){
            mid = (left+right)/2;
            if(numbers[mid]>numbers[right]){
                left = mid+1;
            }else if(numbers[mid]==numbers[right]){
                right--;
            }else{
                right = mid;
            }
        }
        return numbers[left];
    }
};