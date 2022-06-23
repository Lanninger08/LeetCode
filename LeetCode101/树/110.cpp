#include <math.h>
#include <TreeNode.h>
using namespace std;

bool isBalanced(TreeNode* root) {
    return helper(root)!=-1;
}

int helper(TreeNode* root){
    if(root==nullptr) return 0;
    int left = helper(root->left);
    int right = helper(root->right);
    if(left==-1||right==-1||abs(left-right)>1) return -1;
    return max(left, right)+1;
}