/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans = nums[0];
        int max_product = nums[0];
        // 关键，因为存在负数，所以要维护一个最小的值
        int min_product = nums[0];

        for(int i = 1 ; i < nums.size(); ++i){

            int tmp_max = max_product;
            max_product = max(max(nums[i], max_product*nums[i]),min_product*nums[i]);
            min_product = min(min(nums[i], tmp_max*nums[i]),min_product*nums[i]);
            ans = max(ans,max_product);
        }

        return ans;
    }
};
// @lc code=end

