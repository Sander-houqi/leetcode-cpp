/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    // 时间复杂度 O(n∗n!)，n!是回溯算法的时间复杂度，n是序列的长度。
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0 ,ans);
        return ans;

    }

    void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
        if (level==nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for (int i = level; i < nums.size(); ++i){
            //一定包含本身的交换，否则会少情形
            swap(nums[i],nums[level]);
            backtracking(nums,level+1,ans);
            swap(nums[level],nums[i]);
        }
    }
};
// @lc code=end

