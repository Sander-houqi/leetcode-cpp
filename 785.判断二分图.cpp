/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0) return true;

        //0表示未染色，1/2表示不同的颜色
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(!color[i]){
                q.push(i);
                color[i] = 1;
            }

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for(const int & j: graph[node]){
                    if(color[j]==0){
                        q.push(j);
                        //给相邻边赋予和当前不同的颜色
                        color[j] = color[node]==2 ? 1:2;
                    }else if(color[node] == color[j]){
                        // 如果当前节点和相邻节点有相同颜色，则不是二分图，直接返回；
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

