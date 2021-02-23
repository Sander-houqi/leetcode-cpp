/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        // 数组中的元素作为索引，负数标记是否访问
        for(const int & num :nums){
            int pos = abs(num)-1;
            if(nums[pos]>0){
                nums[pos] = -nums[pos];
            }
        }
        // 没有被标记的，其元素值就大于0
        for(int i =0; i<nums.size();++i){
            if(nums[i]>0){
                // 索引值要+1
                ans.push_back(i+1);
            }
        }
        return ans;

    }
};
// @lc code=end

