// 剑指 Offer 41. 数据流中的中位数
// https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/

#include<vector>
#include<queue>
using namespace std;

class MedianFinder {
public:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> minHeap;
    /** initialize your data structure here. */
    MedianFinder() {
    }

    // 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
    void addNum(int num) {
        /* 
        两堆元素个数一样多时，把元素加入到左边
        个数不一样多时，加入到右边（都需要先加到另一边，然后从另一边堆顶取值）
        */
        if (maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else {
            maxHeap.push(num);
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top()+minHeap.top())/2.0;
        } else {
            return maxHeap.top()*1.0;
        }
    }
};