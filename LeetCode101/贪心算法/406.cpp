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