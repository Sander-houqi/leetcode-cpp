/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 排序+双指针 时间复杂度为O(n^2)
    // 通过去重来降低时间复杂度
    vector<vector<int>> threeSum(vector<int>& nums) {

        int size = nums.size();
        // 特判
        if(size < 3) return {}; 

        vector<vector<int>> res;
        std::sort(nums.begin(),nums.end());

        // 固定第一个数
        for(int i = 0 ; i < size ; ++i){
            
            // 第一个数大于0，直接返回
            if(nums[i] > 0) return res;
            // 去重，如果已经被选取，则跳过
            if(i>0 && nums[i]==nums[i-1]) continue;
            // 双指针
            int left =  i + 1;
            int right = size - 1;
            while (left<right)
            {   
                //三数之和小于0，左指针右移
                if(nums[i]+nums[left]+nums[right]<0){
                    ++left;
                //右指针左移
                }else if(nums[i]+nums[left]+nums[right]>0){
                    --right;
                }else{
                    // 存储并移动两个指针
                    res.push_back({nums[i],nums[left++],nums[right--]});
                    // 去重，left和right分别代表第二个数和第三个数
                    while(left < right && nums[left]==nums[left-1]) left++;
                    while(left < right && nums[right]==nums[right+1]) right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

