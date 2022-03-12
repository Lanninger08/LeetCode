class Solution {
    List<List<Integer>> res = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();
    public List<List<Integer>> pathSum(TreeNode root, int target) {
        recur(root, target);
        return res;
    }
    public void recur(TreeNode root, int target){
        if(root==null) return;
        path.add(root.val);
        if(target==root.val && root.left==null && root.right==null) res.add(new LinkedList(path));
        recur(root.left, target-root.val); 
        recur(root.right, target-root.val); 
        path.removeLast();
    }
}

/*
注意事项
1. LinkedList removeLast
2. res.add的时候要新建一个对象，否则全是同一个list（path）
3. 不能通过判断当前val和target的大小关系进行剪枝，因为要考虑正负数问题
*/