// 剑指 Offer 13. 机器人的运动范围
// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

// 搜索问题：深度优先(递归) / 广度优先(queue)

#include<vector>
#include<queue>
#include<utility>  //pair
using namespace std;

class Solution {
public:
    int digitSum(int x, int y){
        int ans = 0;
        while(x != 0){
            ans += x % 10;
            x /= 10;
        }
        while(y != 0){
            ans += y % 10;
            y /= 10;
        }
        return ans;
    }

    /** 
     * 方法1: 深度优先（递归）
     * 先定义位数和函数
     * 在递归阶段，
     * step1，设置递归出口（三种情况：越界/位数和过大/已访问过）
     * step2，需要更新当前状态（设置visit）
     * step3，解决子问题，本题中是把四个方向的结果加起来，再+1（当前格子）
     */
    int dfs(int x, int y, int m, int n, int k, vector<vector<bool>>& visited){
        if(x<0 || y<0 || x>=m || y>=n || digitSum(x, y)>k || visited[x][y]){
            return 0;
        }
        visited[x][y] = true;
        return 1+dfs(x+1,y,m,n,k,visited)+dfs(x-1,y,m,n,k,visited)+dfs(x,y+1,m,n,k,visited)+dfs(x,y-1,m,n,k,visited);
    }

    int movingCount1(int m, int n, int k) {
        vector<vector<bool> > visited(m, vector<bool>(n));
        int ans = dfs(0,0,m,n,k,visited);
        return ans;
    }

    /**
     * 方法2: 深度优先的优化 可以只向下或向右，所以遍历每一个格子，判断是否可达
     * 判断 (i,j) 的位置是否可以进入，需要确认两个条件
     * 1）(i,j) 的数位和是否符合要求
     * 2）(i-1,j) 或者 (i,j-1) 是否有一个可达 
     */
    int movingCount2(int m, int n, int k) {
        vector<vector<int> > visited(m, vector<int>(n));
        int ans = 1;
        visited[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 && j==0) || digitSum(i,j)>k){
                    continue;
                }
                if(j>0) visited[i][j] |= visited[i][j-1];
                if(i>0) visited[i][j] |= visited[i-1][j];
                ans += visited[i][j];
            }
        }
        return ans;
    }

    /**
     * 方法3: 广度优先搜索，使用队列
     */
    int movingCount3(int m, int n, int k) {
        vector<vector<int> > visited(m, vector<int>(n));
        queue<pair<int,int>> Q;
        // 方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        Q.push(make_pair(0,0));
        int ans = 1;
        visited[0][0] = 1;
        while(!Q.empty()){
            pair<int, int> p = Q.front();
            Q.pop();
            for(int i=0;i<2;++i){
                int tx = dx[i] + p.first;
                int ty = dy[i] + p.second;
                if(tx < 0 || tx >= m || ty < 0 || ty >= n || visited[tx][ty] || digitSum(tx, ty) > k) continue;
                Q.push(make_pair(tx, ty));
                visited[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
};
