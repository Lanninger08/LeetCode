// 剑指 Offer 28. 对称的二叉树
// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return recur(root->left, root->right);
    }

    bool recur(TreeNode* left, TreeNode* right){
        if((!left)&&(!right)) return true;
        if((!left)||(!right)||left->val!=right->val) return false;
        return recur(left->left, right->right) && recur(left->right, right->left);
    }
};