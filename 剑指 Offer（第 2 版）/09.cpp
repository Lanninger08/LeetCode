// 剑指 Offer 09. 用两个栈实现队列
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

/* 
维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作。

插入 直接 push 到第一个栈里
删除 如果第二个栈为空，就把第一个栈的元素依次 pop 出来放到第二个栈里，从第二个栈弹出
    如果第二个栈不为空，直接弹出栈顶元素 
*/
#include <stack>
using namespace std;

class CQueue {
    stack<int> stack1,stack2;
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        if (stack2.empty()) {
            return -1;
        } else {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};
