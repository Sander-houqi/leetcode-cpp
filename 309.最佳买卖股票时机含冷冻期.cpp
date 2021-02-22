/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0){
            return 0;
        }

        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> dp(n,vector<int>(3)); 
        dp[0][0] = -prices[0];
        for(int i=1 ; i<n; ++i){
            //手上持有： i-1天持有，i天买入，i-1天且不在冷冻期的减去当天买入价格，也就是买入
            dp[i][0] = max(dp[i-1][0],dp[i-1][2]-prices[i]);
            //手上不持有且在冷冻期: i-1 天持有，当天卖出的价格
            dp[i][1] = dp[i-1][0] + prices[i];
            //手上不持有且不在冷冻期： 即i-1天不持有任何股票
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
        }

        return max(dp[n-1][1],dp[n-1][2]);
    }
};
// @lc code=end

