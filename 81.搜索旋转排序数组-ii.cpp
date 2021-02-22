/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l= 0 , r = nums.size()-1,mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if (nums[mid]==target) return true;
            
            if (nums[mid]==nums[l]){
                ++l;
            //左区间增序
            }else if (nums[mid]>=nums[l]){
                if (target<=nums[mid] && target>=nums[l]){
                    r = mid -1 ;
                }else
                {
                    l = mid +1 ;
                }
            }else
            {   
                if (target>=nums[mid] && target<=nums[r]){
                    l = mid + 1;
                }else
                {   
                    r = mid - 1;
                }
                
            }
        }
        return false;
    }
};


// int main(){
//     int target = 3;
//     vector<int> nums = {3,1,1};
//     bool result = Solution().search(nums, target);
//     cout<< result << endl;

//     return 0;
// }

// @lc code=end

