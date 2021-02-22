/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <vector>
#include <limits.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i =1; i<=n; ++i){
            // j 初始值必须为1；因为dp是从1开始
            for(int j= 1; j*j<=i; ++j){
                //本来应该是dp[i-1],但是由i从1开始，注意开始条件的选择
                dp[i] = min(dp[i],dp[i-j*j]+1); 
            }
        }
        return dp[n];
    }
};
// @lc code=end

