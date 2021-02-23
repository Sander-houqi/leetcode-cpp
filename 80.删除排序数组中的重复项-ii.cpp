/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }

        // 双指针，间隔为2比较，初始值相同
        int i = 2;
        for(int j = 2; j < nums.size(); ++j){
            if(nums[i-2]!= nums[j]){
                // 初值相同，先赋值后++
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
// @lc code=end

