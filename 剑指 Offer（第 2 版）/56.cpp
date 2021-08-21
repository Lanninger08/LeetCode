// 剑指 Offer 56 - I. 数组中数字出现的次数
// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/

#include<cstdio>
#include<vector>
using namespace std;

/*
简化问题： 一个整型数组 nums 里除一个数字之外，其他数字都出现了两次
异或运算有个重要的性质，两个相同数字异或为0。
因此，若将 nums 中所有数字执行异或运算，留下的结果则为出现一次的数字

*/

class Solution
{
public:
    // 注意 (z & m) == 0 一定要带括号！！有优先级问题
    vector<int> singleNumbers(vector<int> &nums)
    {
        int z = 0;
        // 遍历异或整个数组最后得到的结果就是两个只出现一次的数字异或的结果：即 z = x ^ y
        for (int i : nums) z ^= i;
        // z中至少有一位是1，否则x与y就是相等的
        // 通过一个辅助变量m来保存z中哪一位为1.（可能有多个位都为1，我们找到最低位的1即可）
        // z中的1代表x和y不想等的一位，可以用它来把数组区分成两类
        int m = 1;
        while ((z & m) == 0) m <<= 1;
        int x = 0, y = 0;
        for (int i : nums)
        {
            if ((i & m) == 0) x ^= i;
            else y ^= i;
        }
        return vector<int>{x, y};
    }
};

// 剑指 Offer 56 - II. 数组中数字出现的次数 II
// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/

/*
 7 : 0B0111 
 7 : 0B0111
 7 : 0B0111
 5 : 0B0101
 4 : 0B0100
 5 : 0B0101
 5 : 0B0101
        ^^^
        |||
 出现数  736 
        %%%
        333
        ‖‖‖
        100 // 取余结果
*/

// 也可以先排序再找num

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int sub = 0;
        for(int i=0; i<32; ++i){
            sub = 0;
            for(int num: nums) sub += ((num>>i)&1);
            if(sub%3==1) res |= (1<<i);
        }
        return res;
    }
};