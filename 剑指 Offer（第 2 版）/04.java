class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length==0||matrix[0].length==0) return false;
        int n = 0;
        int m = matrix[0].length-1;
        while(matrix[n][m]!=target){
            if(matrix[n][m]<target) n++;
            else if(matrix[n][m]>target) m--;
            if(n>=matrix.length||m<0) return false;
        } 
        return true;
    }
}