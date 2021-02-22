/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include<vector>
#include<limits.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // 可以用bfs（多源点的最短路径优化）和动态规划
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n, INT_MAX-1));

        //左下到右下
        for(int i = 0 ; i < m; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(matrix[i][j]==0){
                    dp[i][j] = 0;
                }else {
                    if (j>0){
                        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                    }
                    if (i>0){
                        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                    }
                }
            }
        }

        //右下到左上
        for(int i = m-1; i>=0; --i){
            for (int j = n-1; j>=0; --j){
                if (matrix[i][j]!=0){
                    if (i<m-1){
                        dp[i][j] = min(dp[i][j],dp[i+1][j]+1);
                    }

                    if (j<n-1){
                        dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
                    }
                   
                }
            }
        }

        return dp;
    }
};
// @lc code=end

