// 剑指 Offer 67. 把字符串转换成整数
// https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/

#include<limits.h>
#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int ans = 0, boundary = INT_MAX/10;
        int i = 0, sign = 1,len = str.size();
        if(len==0) return 0;
        while(str[i]==' ') {
            if(++i==len) return 0;
        }
        if(str[i]=='-') sign=-1;
        if(str[i]=='-'||str[i]=='+') i++;
        for(int j=i;j<len;j++) {
            if(str[j]<'0'||str[j]>'9') break;
            if(ans > boundary || (ans==boundary&&str[j]>'7'))
                return sign==1?INT_MAX:INT_MIN;
            ans = ans*10+(str[j]-'0');
        }
        return ans * sign;
    }
};