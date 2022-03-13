#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt=0, index=0;
    while(cnt<g.size() && index<s.size()){
        if(g[cnt]<=s[index]) cnt++;
        index++;
    }
    return cnt;
}

/*
贪心算法：因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽量使得剩下的饼干可
以满足饥饿度更大的孩子，所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这
个孩子。满足了这个孩子之后，我们采取同样的策略，考虑剩下孩子里饥饿度最小的孩子，直到
没有满足条件的饼干存在。

一开始把while写的很复杂，遍历了每一个child，并且for循环中的每一个操作都在判断index

题解的写法说明：不管是什么情况index都要++，但cnt只有在满足条件的情况下才会++
cnt其实就同时代表了children的index以及满足条件的个数
*/