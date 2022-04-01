#include <vector>
#include <algorithm>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    if(nums.size()==1) return true;
    // 保证后续 nums[i-1] <= nums[i]成立，flag标志是否还有修改机会
    bool flag = (nums[0]<=nums[1]) ? true : false;
    for(int i=1; i<nums.size()-1 ;i++){
        if(nums[i]>nums[i+1]){
            if(flag){
                if(nums[i-1]<=nums[i+1]){
                    // nums[i] > nums[i+1] >= nums[i-1] 比如 2 5 4 这时候应该改i
                    nums[i] = nums[i-1];
                }else{
                    // nums[i] >= nums[i-1] > nums[i+1] 比如 2 5 1 这时候只能改i+1
                    nums[i+1] = nums[i];;
                }
                flag = false;
            }else return false;;
        }
    }
    return true;
}