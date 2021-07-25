// 剑指 Offer 31. 栈的压入、弹出序列
// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    // 时间O(n) 空间O(n)
    /*
    1. 初始化： 辅助栈 stack ，弹出序列的索引 i ；
    2. 遍历压栈序列： 各元素记为 num
            a. 元素 num 入栈；
            b. 循环出栈：若 stack 的栈顶元素 == 弹出序列元素 popped[i] ，则执行出栈与 i++ ；
    3. 返回值： 若 stack 为空，则此弹出序列合法。 */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pop_index=0;
        for(int i=0;i<pushed.size();++i){
            s.push(pushed[i]);
            while((!s.empty())&&s.top()==popped[pop_index]){
                s.pop();
                ++pop_index;
            }
        }
        if(s.empty()) return true;
        else return false;
    }

    // 时间O(n) 空间O(1) 把原数组当成栈使用
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pop_index=0, push_index=0;
        for(int i=0;i<pushed.size();++i){
            pushed[push_index] = pushed[i];
            while(push_index>=0 && pushed[push_index]==popped[pop_index]){
                ++pop_index;
                --push_index;
            }
            ++push_index;
        }
        return push_index==0;
    }
};