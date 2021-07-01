// 剑指 Offer 05. 替换空格
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        // cpp 中 string 的特性
        for(char &c:s){
            if(c == ' '){
                ans += "%20";
            }else{
                ans += c;
            }
        }
        return ans;
    }
};
