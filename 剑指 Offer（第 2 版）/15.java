public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        // 1. 注意因为是无符号数，不能把条件写成n>0
        while(n!=0){
            if((n&1)==1) count++;
            // 2. java中无符号位移是>>>
            n >>>= 1;
        }
        return count;
    }
}