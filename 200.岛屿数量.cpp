/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
    
    vector<int> direction{-1,0,1,0,-1};

public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int nums = 0;
        for(int i =0 ; i<grid.size(); ++i){
            for(int j = 0 ; j<grid[0].size(); ++j){
                if(grid[i][j]=='1'){
                    ++nums;
                    dfs(grid,i,j);
                }
            }
        }
        return nums;
    }

    //dfs访问四邻域    
    void dfs(vector<vector<char>> &grid, int r, int c){
        // 一定要要终止条件
        if(grid[r][c]=='0') return;

        //访问过的置为0
        grid[r][c] = '0';

        int x,y;
        for(int k=0; k<4; ++k){
            x = r + direction[k], y = c + direction[k+1];
            if(x>=0 && x< grid.size() && y>=0 && y< grid[0].size()){
                dfs(grid,x,y);
            }
        }
    }
};
// @lc code=end

