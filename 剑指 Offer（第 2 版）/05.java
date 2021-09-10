class Solution {
    public String replaceSpace(String s) {
        StringBuilder ans = new StringBuilder();
        for (Character c: s.toCharArray()) {
            if (c==' ') ans.append("%20");
            else ans.append(c);
        }
        return ans.toString();
        // 或者直接 return s.replace(" ", "%20");
    }
}