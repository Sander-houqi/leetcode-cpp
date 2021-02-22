/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include<vector>
#include<string>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // 吐槽: 不知道第几遍刷了，还是不会写，太蠢了吧。。
    int longestCommonSubsequence(string text1, string text2) {
        // string length 和 size 方法均可，没什么区别
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1; i <=m; ++i){
            for(int j= 1; j<=n; ++j){
                if (text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                    // cout<< text1[i-1] <<endl;
                }else
                {   
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

