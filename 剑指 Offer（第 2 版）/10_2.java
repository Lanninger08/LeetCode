class Solution {
    public int numWays(int n) {
        if(n==0) return 1;
        int a = 1, b = 1, tmp;
        for(int i=2;i<=n;++i) {
            tmp = (a+b)%1000000007;
            a = b;
            b = tmp;
        }
        return b;
    }
}