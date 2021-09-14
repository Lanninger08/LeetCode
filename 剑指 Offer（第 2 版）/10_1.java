class Solution {
    public int fib(int n) {
        if(n==0||n==1) return n;
        int a = 0;
        int b = 1;
        for(int i=2;i<=n;++i){
            int nxt = (a+b)%1000000007;
            a = b;
            b = nxt;
        }
        return b;
    }
}