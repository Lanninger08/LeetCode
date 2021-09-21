class Solution {
    public int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int m = n/3;
        int reminder = n%3;
        if(reminder==0){
            return (int)Math.pow(3, m);
        }else if(reminder==1){
            return (int)Math.pow(3, m-1)*4;
        }else{
            return (int)Math.pow(3, m)*2;
        }
    }
}