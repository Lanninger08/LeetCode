/*
    和上一题的区别在于大数求余
    python 好像很适合快速幂，有a//=2 的操作
*/

class Solution {
    public int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        long res = 1L;
        int p = 1000000007;
        while(n>4){
            res = (res*3)%p;
            n -= 3;
        }
        return (int)((res*n)%p);
    }
}