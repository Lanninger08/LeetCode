// 剑指 Offer 20. 表示数值的字符串
// https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

#include <string>
using namespace std;

class Solution
{
public:
    // 逐位遍历并做好标记
    bool isNumber(string s)
    {
        int len = s.length();
        bool hasNum = false, hasDot = false, hasE = false, hasSign = false;
        int index = 0;
        // 去掉空格
        while (index < len && s[index] == ' ')
        {
            ++index;
        }
        while (index < len)
        {
            while (index < len && s[index] >= '0' && s[index] <= '9')
            {
                index++;
                hasNum = true;
            }
            if (index == len)
                break;
            if (s[index] == 'e' || s[index] == 'E')
            {
                // 如果e已经出现或者当前e之前没有出现过数字
                if (hasE || !hasNum)
                    return false;
                // hasE = true，并且将其他3个flag全部置为false，因为要开始遍历e后面的新数字了
                hasE = true;
                hasDot = hasNum = hasSign = false;
            }
            else if (s[index] == '.')
            {
                if (hasDot || hasE)
                    return false;
                hasDot = true;
            }
            else if (s[index] == '+' || s[index] == '-')
            {
                if (hasSign || hasNum || hasDot)
                    return false;
                hasSign = true;
            }
            else if (s[index] == ' ')
            {
                break;
            }
            else
            {
                return false;
            }
            ++index;
        }
        while (index < len && s[index] == ' ')
        {
            ++index;
        }
        return hasNum && index == len;
    }
};