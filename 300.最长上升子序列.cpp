/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 动态规划时间复杂度O(n^2，还可以使用二分查找优化，不过我看不懂。。。)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() , max_length = 0;
        if (n<=1) return n;
        vector<int> dp(n,0);
        for(int i =0; i < n; i++){
            //初始值是1;
            dp[i]=1;
            for(int j = 0; j < i; j++){
                if (nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j] +1) ;
                }
            }
            max_length = max(max_length,dp[i]);
        }
        return max_length;
    }
};
// @lc code=end

