/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    //dp 加动态规划
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for(int i=1; i<=num; ++i){
            //右移一位+最后一位是否是1；
            dp[i] = dp[i>>1] + (i&1);
        }
        return dp;
    }
};
// @lc code=end

