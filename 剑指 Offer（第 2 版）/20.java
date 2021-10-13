// 要注意的地方
// 1. 全局变量 index
// 2. 判断index有没有越界
class Solution {
    public int index;
    private boolean scanInteger(String s){
        if(index!=s.length() && (s.charAt(index)=='+'||s.charAt(index)=='-')) ++index;
        return scanUnsignedInteger(s);
    }
    private boolean scanUnsignedInteger(String s){
        int before = index;
        while(index!=s.length() && s.charAt(index)<='9' && s.charAt(index)>='0') ++index;
        return index>before;
    }

    public boolean isNumber(String s) {
        if(s.length()==0) return false;
        index = 0;
        // 考虑空格
        while(index!=s.length() && s.charAt(index)==' ') ++index;
        // 整数部分
        boolean numeric = scanInteger(s);
        // 如果有小数
        if(index!=s.length() && s.charAt(index)=='.'){
            ++index;
            // 小数点前可以没有整数，小数点后也可以没有整数
            numeric = scanUnsignedInteger(s) || numeric;
        }
        if(index!=s.length() && (s.charAt(index)=='e'||s.charAt(index)=='E')){
            ++index;
            // e前后都必须有数字
            numeric = numeric && scanInteger(s);
        }
        while(index!=s.length() && s.charAt(index)==' ') ++index;
        return numeric && (index==s.length());
    }
}