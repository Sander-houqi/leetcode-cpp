/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    //双指针法
    // int removeDuplicates(vector<int>& nums) {
    //     if(nums.empty()) return 0;

    //     int i = 0;
    //     for(int j = 1; j < nums.size(); ++j){
    //         if(nums[i]!=nums[j]){
    //             // 注意是++i
    //             nums[++i] = nums[j];
    //         }
    //     }
    //     //i是索引，所以要+1，返回数组长度
    //     return i+1;
    // }


    //注意初始化和返回结果不同
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int i = 1;
        for(int j = 1; j < nums.size(); ++j){
            if(nums[i-1]!=nums[j]){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
// @lc code=end

