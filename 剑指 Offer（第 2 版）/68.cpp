// 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while(true) {
            if (p->val<ancestor->val && q->val<ancestor->val){
                ancestor = ancestor->left;
            }else if (p->val>ancestor->val && q->val>ancestor->val){
                ancestor = ancestor->right;
            }else{
                break;
            }
        }
        return ancestor;
    }
};