/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size() , n = matrix[0].size() , count=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0 ; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (matrix[i][j]== 1){
                    if (i==0 || j==0){
                        dp[i][j] = 1;
                    }else
                    {
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};
// @lc code=end

