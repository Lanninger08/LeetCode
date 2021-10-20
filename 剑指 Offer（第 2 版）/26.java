public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        return (B!=null && A!=null) && (recur(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B));
    }
    public boolean recur(TreeNode A, TreeNode B){
        if(B==null)return true;
        if(A==null || A.val!=B.val) return false;
        return recur(A.left, B.left)&&recur(A.right, B.right);
    }
}