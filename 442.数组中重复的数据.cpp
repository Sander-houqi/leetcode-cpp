/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */
#include<vector>
#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // 要求空间复杂度为常数，那么就必须原地修改
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;

        for(int i=0; i< nums.size(); ++i){
            int num = abs(nums[i]);

            //利用num的值来当索引，因为数组的范围在[1,n]之间
            if(nums[num-1]>0){
                nums[num-1] *= -1;
            }else
            {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
// @lc code=end

