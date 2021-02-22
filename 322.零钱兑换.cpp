/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        // 一维的空间复杂度 完全背包问题
        vector<int> dp(amount+1,amount+2);
        dp[0]=0;
        for(int i =1; i<=amount;++i){
            for(const int & coin :coins){
                if(i>=coin){
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]!=amount+2 ? dp[amount] : -1;

    }
};

