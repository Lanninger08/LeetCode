class Solution {
    public double myPow(double x, int n) {
        if(x==0) return 0;
        // 要用long，不然−2147483648会报错
        /* Java 代码中 int32 变量 n 的范围 [-2147483648, 2147483647]
        因此当 n = -2147483648 时执行 n = -n 会因越界而赋值出错。
        解决方法是先将 n 存入 long 变量 b ，后面用 b 操作即可。*/
        long b = n;
        if(b<0) {
            x = 1/x;
            b = -b;
        }
        double res = 1.0;
        while(b>0){
            if(b%2==1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
}