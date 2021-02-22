/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 空间复杂度O(n)
    // int rob(vector<int>& nums) {
    //     if (nums.empty()) return 0 ;
    //     int n = nums.size();
    //     // 如果同时给出dp[0]、dp[1]那么需要加上这个判断，防止数组越界
    //     if (n==1) return nums[0];
    //     vector<int> dp(n,0);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0],nums[1]);
    //     for(int i = 2; i< n; ++i){
    //         dp[i] = max(dp[i-1], dp[i-2]+ nums[i]);
    //     }
    //     return dp[n-1];
    // }

    // 空间复杂度O(1)
    int rob(vector<int> & nums){
        if (nums.empty()) return 0;
        int  n = nums.size();
        if (n==1) return nums[0];
        int pre1 = nums[0] , pre2 = max(nums[0],nums[1]) , cur;
        for(int i = 2; i < n ; ++i){
            cur = max(pre1+nums[i],pre2);
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};
// @lc code=end

