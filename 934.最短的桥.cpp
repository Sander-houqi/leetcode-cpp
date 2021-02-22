/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};

    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size() , n = A[0].size();
        queue<pair<int,int>> points;
        bool flag = false;
        // dfs 得到第一个岛屿
        for(int i = 0 ; i < m; ++i){
            if (flag) break;
            for(int j = 0; j < n; ++j){
                if (A[i][j]==1){
                    dfs(A,points,i,j);
                    flag = true;
                    break;
                }
            }
        }

        //bfs 得到第二个岛屿
        int x,y;
        int level=0;
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            //points 存放的是dfs得到的岛屿的边界，所以一次搜索相当于所有的的边界向四周搜索一次。
            while (n_points--)
            {
                auto [r,c] = points.front();
                points.pop();
                for(int k =0 ; k < 4; ++k){
                    x = r + direction[k] , y = c + direction[k+1];
                    if (x >= 0 && x < m && y>=0 && y<n){
                        if (A[x][y]==2) continue;
                        if (A[x][y]==1) return level;

                        points.push({x,y});
                        A[x][y] = 2;
                    }
                }

            }
            
        }
        return 0 ;
    }

    void dfs(vector<vector<int>>& A,queue<pair<int,int>> & points, int i , int j){
        //停止条件可以放在开始，或者在下面四邻域遍历的时候
        if (i<0 || i>= A.size() || j<0 || j >= A[0].size() || A[i][j]==2) return;
        
        // 如果不是1，则返回，否则继续遍历,并把0的加入到queue中
        if (A[i][j] == 0){
            points.push({i,j});
            return;
        }

        A[i][j]=2;
        int x,y ;
        for(int k=0 ; k<4; ++k){
            x = i + direction[k], y = j +direction[k+1];
            dfs(A,points,x,y);
        }
    }

};
// @lc code=end

