/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 题解参考81题
    int search(vector<int>& nums, int target) {
        
        int n = nums.size(), l = 0 , r = n-1 ;
        while (l<=r)
        {
            int mid = l + (r-l) /2;

            if(nums[mid] == target){
                return mid;
            }else if (nums[mid]>=nums[l]) //左区间有序
            {   
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid - 1;
                }else
                {
                    l = mid + 1;
                }
            // 右区间有序
            }else
            {
                if(nums[mid]<= target && target <= nums[r]){
                    l = mid + 1;
                }else
                {
                    r = mid -1 ;
                }
            }
        }
        return -1;        
    }
};
// @lc code=end

