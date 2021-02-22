/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(),count = 0;
        vector<bool> visited(n,false);
        // 一共有多少个朋友圈，每个朋友圈最大有多少。
        for(int i = 0; i < n;++i){
            if (!visited[i]){
                dfs(M,i,visited);
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& M , int i, vector<bool>& visited){
        // return 这个条件判断是和for循环中的visited是等同的。
        // if (visited[i]) return;
        visited[i]=true;
        for(int j = 0; j < M.size(); ++j){
            // 访问过的节点不在访问
            if(M[i][j]==1 && !visited[j]){
                dfs(M,j,visited);
            }
        }

    }
};
// @lc code=end

