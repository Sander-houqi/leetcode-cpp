/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1,-1};
        int lower = lower_bound(nums,target);
        int upper = upper_bound(nums,target);
        return vector<int>{lower,upper};
    }

    int lower_bound(vector<int>& nums, int target){
        int l = 0 , r = nums.size(), mid;
        while(l<r){
            mid = l + (r -l)/ 2;
            if (nums[mid]==target){
                r = mid;
            }else if(nums[mid] > target){
                r = mid;
            }else
            {
                l = mid +1;
            }
        }
        if (l>=nums.size() || nums[l]!=target){
            return -1;
        }
        
        return l;
    }

    int upper_bound(vector<int>& nums, int target){
        int l = 0 , r = nums.size(), mid ;
        while (l<r)
        {
            mid = l + (r-l)/2;
            if (nums[mid]==target){
                l = mid + 1;
            }else if(nums[mid] > target){
                r = mid;
            }else
            {
                l = mid + 1;
            }
            
        }

        if (r<=0 || nums[r-1]!=target){
            return - 1;
        }

        return r-1;
    }
};
// @lc code=end

