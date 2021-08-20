// 剑指 Offer 55 - I. 二叉树的深度
// https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/

#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归
    int maxDepth1(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth1(root->left), maxDepth1(root->right))+1;
    }
    // BFS
    int maxDepth2(TreeNode* root) {
        if(root==NULL) return 0;
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ++depth;
            for(int i=0; i<size; ++i){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
        }
        return depth;
    }
};

// 剑指 Offer 55 - II. 平衡二叉树
// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }

    int recur(TreeNode* node) {
        if (node == NULL) return 0;
        int left = recur(node->left);
        if (left == -1) return -1;
        int right = recur(node->right);
        if (right == -1) return -1;
        return abs(left-right)<2 ? max(left,right)+1 :-1;
    }
};
