#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 受区间排序思想影响 不够简洁（内存消耗较大）
vector<int> partitionLabels(string s) {
    vector<int> start(26, -1);
    vector<int> end(26, 0);
    for(int i=0; i<s.size(); i++){
        if(start[s[i]-'a']==-1) start[s[i]-'a']=i;
        end[s[i]-'a']=i;
    }
    vector<vector<int>> interval;
    for(int i=0; i<26; i++){
        if(start[i]!=-1){
            interval.push_back(vector<int>{start[i], end[i]});
        }
    }
    sort(interval.begin(), interval.end(), [](vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    });
    vector<int> partition;
    int prev_start=0, prev_end=interval[0][1];
    for(int i=1; i<interval.size(); i++){
        if(interval[i][0]>=prev_end){
            partition.push_back(prev_end-prev_start+1);
            prev_start = prev_end+1;
            prev_end = end[s[prev_start]-'a'];
        }else if(interval[i][1]>prev_end) prev_end = interval[i][1];
    }
    partition.push_back(prev_end-prev_start+1);
    return partition;
}