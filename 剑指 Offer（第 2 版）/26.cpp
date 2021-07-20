// 剑指 Offer 26. 树的子结构
// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A && B) && (recur(A,B)||isSubStructure(A->left, B)||isSubStructure(A->right, B));
    }

    bool recur(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A||A->val!=B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};