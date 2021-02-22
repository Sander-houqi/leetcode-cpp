/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     if(matrix.empty() || matrix[0].empty()) return 0;
    //     int m = matrix.size() , n = matrix[0].size(), max_side=0;
    //     //第一行和第一列添加0
    //     //dp[i][j]表示以[i,j]为右下角的正方形最大边长，或者以[i,j]为右下角的正方形的数目见1227题。
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    //     //边界条件一定注意
    //     for(int i = 1; i <= m; ++i){
    //         for(int j = 1; j <= n; ++j){
    //             if (matrix[i-1][j-1]=='1'){
    //                 // 推导见leetcode；
    //                 dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
    //             }
    //             max_side = max(max_side,dp[i][j]);
    //         }
    //     }

    //     return max_side*max_side;
    // }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size() , n = matrix[0].size() , max_side=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0 ; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (matrix[i][j]== '1'){
                    if (i==0 || j==0){
                        dp[i][j] = 1;
                    }else
                    {
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }
                }
                max_side =  max(max_side,dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};
// @lc code=end

