#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    auto cmp = [&](vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    };
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> res;
    for(int i=0; i<people.size() ;i++){
        res.insert(res.begin()+people[i][1], people[i]);
    }
    return res;
}

//从 A 里挑身高最高的人 x 出来，插入到 B. 因为 B 中每个人的身高都比 x 要高，因此 x 插入的位置，就是看 x 前面应该有多少人就行了。