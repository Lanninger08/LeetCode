public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root==null) return true;
        return recur(root.left, root.right);
    }
    public boolean recur(TreeNode left, TreeNode right){
        if(left==null&&right==null) return true;
        if(left==null||right==null||left.val!=right.val) return false;
        // 传进去的是需要对称的两棵小树的根
        return recur(left.left, right.right) && recur(left.right, right.left);
    }
}