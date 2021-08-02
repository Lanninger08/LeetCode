// 剑指 Offer 38. 字符串的排列
// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/

#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
    void dfs(string s, int x){
        if(x == s.size()-1){
            res.push_back(s);
            return;
        }
        set<int> st;
        for(int i=x;i<s.size();++i){
            if(st.find(s[i]) != st.end()) continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x+1);
            swap(s[i], s[x]);
        }
    }
};