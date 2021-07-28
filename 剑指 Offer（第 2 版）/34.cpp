// 剑指 Offer 34. 二叉树中和为某一值的路径
// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/

#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 当前路径
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }
    void dfs(TreeNode* curr, int target){
        if(curr){
            target -= curr->val;
            path.push_back(curr->val);
            if(target!=0 || curr->left || curr->right){
                dfs(curr->left, target);
                dfs(curr->right, target);
            }else{
                res.push_back(path);
            }
            // 回溯
            path.pop_back();
        }
    }
};