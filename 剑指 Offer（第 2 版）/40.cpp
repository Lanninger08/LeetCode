// 剑指 Offer 40. 最小的k个数
// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

#include<vector>
#include<queue>
using namespace std;

/*
    方法一：堆（优先队列）只保留k个数 时间复杂度O(n logk) 空间复杂度O(k)
    方法二：快排思想 时间复杂度O(n^2) 空间复杂度O(n) 
*/

class Solution {
public:
    vector<int> getLeastNumbers1(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if(k == 0){
            return ans;
        }
        priority_queue<int> pq;
        for(int i=0; i<k; ++i) {
            pq.push(arr[i]);
        }
        for(int i=k; i<arr.size(); ++i){
            if(pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for(int i=0; i<k; ++i) {
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0 || arr.size()==0) return {};
        return quickSort(arr, 0, arr.size()-1, k-1);
    }

    vector<int> quickSort(vector<int>& arr, int low, int high, int k) {
        int pivot = partition(arr, low, high);
        vector<int> res;
        if(pivot == k){
            res.assign(arr.begin(), arr.begin() + k + 1);
        }else{
            if(pivot>k) res = quickSort(arr, low, pivot-1, k);
            else res = quickSort(arr, pivot+1, high, k);
        }
        return res;
    }

    int partition(vector<int>& arr, int low, int high) {
        int val = arr[low];
        int i = low, j = high+1;
        int tmp;
        while(true) {
            while(++i <= high && arr[i] < val);
            while(--j >= low && arr[j] > val);
            if (i >= j) break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
        arr[low] = arr[j];
        arr[j] = val;
        return j;
    }
};