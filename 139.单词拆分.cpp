/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,false);
        // 位置0,必须初始化为真
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(const auto & word : wordDict){
                int len = word.length();
                if (i>=len && s.substr(i-len,len) == word){
                    dp[i] = dp[i] || dp[i-len];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

