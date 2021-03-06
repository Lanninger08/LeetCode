// 剑指 Offer 59 - I. 滑动窗口的最大值
// https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/

#include<vector>
#include<deque>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 特判 数组大小为0/滑动窗口大小为0
        if(nums.size()==0 || k==0) return {};

        // 单调队列（双端队列）
        deque<int> dq;
        vector<int> res;

        // 滑动窗口未形成 - dq里存当前元素 移除比当前元素小的数
        for(int i=0;i<k;++i){
            while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        // 窗口形成 - dq存当前元素，去掉比当前元素小的，以及刚移出滑动窗口里的nums[i-k]
        for(int i=k;i<nums.size();++i){
            if(dq[0]==nums[i-k]) dq.pop_front();
            while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            res.push_back(dq[0]);
        }
        return res;
    }
};

// 剑指 Offer 59 - II. 队列的最大值
// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/

class MaxQueue {
    queue<int> q;
    deque<int> dq;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (dq.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!dq.empty() && value>dq.back()) dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int res = q.front();
        q.pop();
        if(res==dq.front()) dq.pop_front();
        return res;
    }
};