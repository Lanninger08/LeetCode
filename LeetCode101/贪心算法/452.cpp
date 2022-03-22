#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size()==0) return 0;
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    });
    int cnt = 1, prev = points[0][1];
    for(int i=1; i<points.size(); i++){
        if(points[i][0]>prev){
            cnt++;
            prev = points[i][1];
        }
    }
    return cnt;
}

/*
第一个会超时，为什么
sort(points.begin(),points.end(),[](vector<int> a,vector<int> b){
        return a[1] < b[1];

sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
        return a[1] < b[1];

第一个传值要调用copy ctor，开销大，第二个是传引用
*/