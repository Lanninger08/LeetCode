// 剑指 Offer 30. 包含min函数的栈
// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/

#include<stack>
using namespace std;

// 辅助栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(min_stack.empty() || x<=min_stack.top()) min_stack.push(x);
        s.push(x);
    }
    
    void pop() {
        if(s.top()==min_stack.top()) min_stack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return min_stack.top();
    }
private:
    stack<int> min_stack;
    stack<int> s;
};