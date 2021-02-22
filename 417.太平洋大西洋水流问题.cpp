/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        vector<vector<int>> ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> reach_p(m,vector<bool>(n, false));
        vector<vector<bool>> reach_a(m,vector<bool>(n, false));

        //dfs 四个边
        //cols
        for(int i = 0; i < m ; ++i){
            //pacific
            dfs(matrix,reach_p,i,0);
            //atlantic
            dfs(matrix,reach_a,i,n-1);
        }
        //rows
        for(int i = 0; i < n ; ++i){
            dfs(matrix,reach_p,0,i);
            dfs(matrix,reach_a,m-1,i);
        }

        //同时满足两边可到达的点
        for(int i = 0; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if (reach_p[i][j] && reach_a[i][j]){
                    ans.push_back(vector<int>{i,j});
                }
            }
        }

        return ans;

    }

    void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& reach, int r, int c){
        if (reach[r][c]) return;

        reach[r][c]= true;
        int x,y;
        for(int k = 0; k < 4; ++k){
            x = r + direction[k], y = c + direction[k+1];
            //海拔从低到高
            if(x>=0 && x<matrix.size() && y>=0 && y < matrix[0].size() && matrix[r][c]<=matrix[x][y]){
                dfs(matrix,reach,x,y);
            }
        }
    }

};
// @lc code=end

