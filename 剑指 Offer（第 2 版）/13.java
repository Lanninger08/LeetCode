class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] visited = new boolean[m][n];
        int ans = dfs(0, 0, m, n, k, visited);
        return ans;
    }

    public int dfs(int i, int j, int m, int n, int k, boolean[][] visited) {
        if(i<0 || i>=m || j<0 || j>=n || digitSum(i, j)>k || visited[i][j]) return 0;
        visited[i][j] = true;
        return 1+dfs(i+1,j,m,n,k,visited)+dfs(i-1,j,m,n,k,visited)+dfs(i,j+1,m,n,k,visited)+dfs(i,j-1,m,n,k,visited);
    }
    public int digitSum(int x, int y){
        int ans = 0;
        while(x != 0){
            ans += x % 10;
            x /= 10;
        }
        while(y != 0){
            ans += y % 10;
            y /= 10;
        }
        return ans;
    }
}