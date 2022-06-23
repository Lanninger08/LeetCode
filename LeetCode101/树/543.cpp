#include <vector>
#include <algorithm>
#include <TreeNode.h>
using namespace std;

int ans = 0;
int diameterOfBinaryTree(TreeNode* root) {
    getHeight(root);
    return ans;
}
int getHeight(TreeNode* node){
    if(node==nullptr) return 0;
    int l = getHeight(node->left);
    int r = getHeight(node->right);
    ans = max(l+r, ans);
    return max(l,r)+1;
}