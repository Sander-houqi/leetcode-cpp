/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include<vector>
#include<deque>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        //双向队列 保存当前窗口最大值的数组位置 保证队列中数组位置的数值按从大到小排序
        deque<int> dq;
        vector<int> ans;

        for(int i =0; i<nums.size();++i){
            //队首的索引如果不在当前窗口弹出
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

             // 保证从大到小 如果前面数小则需要依次弹出，直至满足要求
            while (!dq.empty() && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            // 添加当前值对应的数组下标
            dq.push_back(i);
            // 当窗口长度为k时 保存当前窗口中最大值
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
            

        }

        return ans;
    }
};
// @lc code=end

