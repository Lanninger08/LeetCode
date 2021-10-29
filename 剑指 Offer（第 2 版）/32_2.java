class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        if(root!=null) q.add(root);
        while(!q.isEmpty()){
            List<Integer> tmp = new ArrayList<>();
            for(int i = q.size(); i > 0; i--) {
                TreeNode node = q.poll();
                tmp.add(node.val);
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            res.add(tmp);
        }
        return res;
    }
}