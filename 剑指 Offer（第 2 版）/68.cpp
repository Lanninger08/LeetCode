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

// 剑指 Offer 68 - II. 二叉树的最近公共祖先
// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 省略了 if(left == nullptr && right == nullptr) return nullptr;
        // 不在left，说明在right
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        // if(left != null and right != null) 说明pq在节点的两侧，当前节点为我们要的值
        return root;
    }
};