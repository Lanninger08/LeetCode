// 剑指 Offer 33. 二叉搜索树的后序遍历序列
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

#include<limits.h>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    /* 方法一：递归分治
    时间复杂度 O(N^2) 每次调用 recur(i,j) 减去一个根节点，因此递归占用 O(N) ；
        最差情况下（即当树退化为链表），每轮递归都需遍历树所有节点，占用 O(N)
    空间复杂度 O(N) ： 最差情况下（即当树退化为链表），递归深度将达到 N 。
    */
    bool verifyPostorder1(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }
    bool recur(vector<int>& postorder, int i, int j){
        if(i >= j) return true;
        int p = i;
        while(postorder[p] < postorder[j]) ++p;
        // 找到右子树的第一个节点(第一个比根节点大的节点)
        int m = p;
        // 验证右子树的所有值是否比根节点大
        while(postorder[p] > postorder[j]) ++p;
        return p==j && recur(postorder, i, m-1) && recur(postorder, m, j-1);
    }

    // 方法二：辅助单调栈 没看懂
    bool verifyPostorder2(vector<int>& postorder) {
        stack<int> s;
        int parent = INT_MAX;
        for(int i=postorder.size()-1;i>=0;--i){
            int cur = postorder[i];
            while(!s.empty() && s.top()>cur){
                parent = s.top();
                s.pop();
            }
            if(cur>parent) return false;
            s.push(cur);
        }
        return true;
    }
};