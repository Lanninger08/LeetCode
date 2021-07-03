// 剑指 Offer 07. 重建二叉树
// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
// 已知前序中序 恢复二叉树

/*
  前序遍历：根左右
  中序遍历：左根右
*/

#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// method1 递归
/*
前序遍历中的第一个节点是根节点
通过前序获得根节点，在中序中找到根节点的位置，区分左子树和右子树

建立根节点，得到左子树的节点数目 size_left_subtree
递归地构造左子树和右子树
先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素

*/
class Solution {
    unordered_map<int, int> index_map;
public:
    TreeNode* recur(vector<int>& preorder, vector<int> &inorder, int pre_start_index, int pre_end_index, int in_start_index, int in_end_index){
        if(pre_start_index>pre_end_index){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_start_index]);
        int root_index = index_map[preorder[pre_start_index]];

        // 得到左子树size 递归构造左子树
        int left_size = root_index - in_start_index;
        root->left = recur(preorder, inorder, pre_start_index+1, pre_start_index+left_size, in_start_index, root_index-1);
        // 递归构造右子树
        root->right = recur(preorder, inorder, pre_start_index+left_size+1, pre_end_index, root_index+1, in_end_index);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            index_map[inorder[i]] = i;
        }
        return recur(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// method2 迭代
/*
前序的第一个元素一定是根节点，而中序的第一个元素不是根节点的话就说明有左子树存在
前序遍历一定会先走左子树，所以接下来一定是存在左子树的节点的，一直到与中序的第一个元素相等为止都是左子树。 
在遍历达到相等的位置时，前序栈弹出，同时中序往后遍历，直到遇到根节点或者不相同元素（说明出现了非左子树节点，应当位于中序的前一个节点的右子树上）。
右子树部分同理

从1遍历一遍preorder，【每次比较栈顶元素和inorder[index] 是否相等】

如果不等：preorder[i] 入栈且将其变为左子树；
如果相等：弹出栈顶元素，index + 1；
就这样一直弹出直到栈顶元素和 inorder[index] 不等时，将 preorder[I] 变为右子树。
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            // 栈顶元素不等于inorder索引的当前元素, 一直进栈, 构建左节点
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                // 栈顶元素和inorder当前索引元素相等时, 出栈, 
                // 直到又不相等了 说明出现右孩子
                // 或者栈为空, 说明该往右走, 找右孩子
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};
