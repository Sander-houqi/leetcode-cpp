/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// @lc code=start
class Solution {
public:
    //还是和三数之和一样的思路 排序+双指针
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        // 用数组中的元素初始化
        int ans = nums[0]+nums[1]+nums[2];

        for(int i = 0; i < nums.size(); ++i){

            int left = i + 1;
            int right = nums.size()-1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                //更新结果
                if(abs(sum-target) < abs(target-ans)){
                    ans  = sum;
                }

                //移动指针
                if(sum>target){
                    right--;
                }else if(sum<target){
                    left++;
                }else
                {
                    return ans;
                }
            }
            
        }
        return ans;
    }
};
// @lc code=end

