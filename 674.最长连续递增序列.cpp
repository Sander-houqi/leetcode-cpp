/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans= 0;
        int start = 0;
        //贪心
        for(int i=0 ; i<nums.size(); ++i){
            //不满足条件直接更新
            if(i>0 && nums[i-1]>=nums[i]){
                start = i;
            }
            ans = max(ans,i-start+1);
        }   
        return ans;
    }
};
// @lc code=end

