/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int cur_sum = nums[0];
        // 全局最大和
        int max_sum = cur_sum;
        for(int i = 1; i< nums.size(); ++i){
            // 当前位置，当前位置+以前的子序和
            cur_sum = max(nums[i],cur_sum + nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};
// @lc code=end

