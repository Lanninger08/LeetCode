class Solution {
    public int[] levelOrder(TreeNode root) {
        if(root==null) return new int[0];
        Queue<TreeNode> q = new LinkedList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode cur = q.poll();
            ans.add(cur.val);
            if(cur.left!=null) q.add(cur.left);
            if(cur.right!=null) q.add(cur.right);
        }
        int[] res = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++)
            res[i] = ans.get(i);
        return res;
    }
}