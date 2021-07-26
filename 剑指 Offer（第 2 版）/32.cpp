// 剑指 Offer 32 - I II III. 从上到下打印二叉树
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

// 用 emplace 代替 push 效率会高一点
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 简单的层序遍历
    vector<int> levelOrder1(TreeNode* root) {
        vector<int> res = {};
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            res.push_back(n->val);
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        return res;
    }

    // 每一层打印到一行
    vector<vector<int>> levelOrder2(TreeNode* root) {
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        vector<int> ans_tmp;
        while(!q.empty()){
            ans_tmp.clear();
            for(int i=q.size();i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                ans_tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(ans_tmp);
        }
        return ans;
    }

    // 奇数行从左到右，偶数行从右到左
    vector<vector<int>> levelOrder3(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        vector<int> ans_tmp; 
        while(!q.empty()){
            ans_tmp.clear();
            for(int i=q.size();i>0;--i){
                TreeNode* node = q.front();
                q.pop();
                ans_tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) ans.push_back(ans_tmp);
            else ans.push_back(vector<int>(ans_tmp.rbegin(), ans_tmp.rend()));
            flag = !flag;
        }
        return ans;
    }
};