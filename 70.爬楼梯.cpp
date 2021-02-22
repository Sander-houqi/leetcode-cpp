/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 空间复杂度O(n)
    // int climbStairs(int n) {
    //     if (n<=2) return n;
    //     vector<int> dp(n+1,1);
    //     for(int i = 2 ; i <= n; ++i){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    // 空间复杂度o(1)
    int climbStairs(int n){
        if (n<=2) return n;
        int tmp1 = 1, tmp2 =1 , cur;
        for (int i = 2; i <= n ; ++i){
            cur = tmp1+tmp2;
            tmp1 = tmp2;
            tmp2 = cur;
        }
        return cur;
    }
};
// @lc code=end

