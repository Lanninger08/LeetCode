// 考虑大数

class Solution {
    StringBuilder res;
    int nine, start, n;
    char[] num, loop = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    public int[] printNumbers(int n) {
        this.n = n;
        num = new char[n];
        res = new StringBuilder();
        start = n-1;
        nine = 0;
        dfs(0);
        res.deleteCharAt(res.length() - 1);
        String str = res.toString();
        String[] ans_s = str.split(",");
        int[] ans = new int[ans_s.length];
        for(int i=0;i<ans_s.length;++i){
            ans[i] = Integer.parseInt(ans_s[i]);
        }
        return ans;
    }
    public void dfs(int x){
        if(x==n) {
            String s = String.valueOf(num).substring(start);
            if(!s.equals("0")) res.append(s + ",");
            // 说明所有n-start位都是9，发生进位
            if(n - start == nine) start--;
            return;
        }
        for(char i: loop){
            if(i == '9') nine++;
            num[x]=i;
            dfs(x+1);
        }
        nine--;
    }
}