// 剑指 Offer 54. 二叉搜索树的第k大节点
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/

#include<cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int k, res;
    // 二叉搜索树中序遍历的倒序是降序
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* node) {
        if(!node) return;
        dfs (node->right);
        if(k==0) return;
        if(--k==0) res = node->val;
        dfs(node->left);
    }
};