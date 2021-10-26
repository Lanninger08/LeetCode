class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length==0||matrix[0].length==0) return new int[0];
        int left = 0, right = matrix[0].length-1, top = 0, bottom = matrix.length-1;
        int[] res = new int[(right + 1) * (bottom + 1)];
        int x=0;
        while(true){
            for(int i=left; i<=right; ++i) res[x++] = matrix[top][i];
            if(++top > bottom) break;
            for(int i=top; i<=bottom; ++i) res[x++] = matrix[i][right];
            if(--right < left) break;
            for(int i=right; i>=left; i--) res[x++] = matrix[bottom][i];
            if(--bottom < top) break;
            for(int i=bottom; i>=top; i--) res[x++] = matrix[i][left];
            if(++left > right) break;
        }
        return res;
    }
}