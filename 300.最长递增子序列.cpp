/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // 动态规划时间复杂度O(n^2，还可以使用二分查找优化，不过我看不懂。。。)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() , max_length = 0;
        if (n<=1) return n;
        vector<int> dp(n,0);
        // result 如果要获得最长递增序列，而不是只求长度
        // vector<vector<int>> result;
        for(int i =0; i < n; i++){
            //初始值是1;
            dp[i]=1;
            vector<int> tmp;
            for(int j = 0; j < i; j++){
                //当前值和之前所有的元素进行比较，只有小于当前值，才填表
                if (nums[j]<nums[i]){
                    
                    //如果要输出最长公共子序列
                    //或者这里只保留最后一个索引，然后在循环外倒着遍历dp数组，参考https://blog.csdn.net/qq_43791377/article/details/89938344
                    // if(tmp.size()>0 && tmp[tmp.size()-1]>nums[j]){
                    //     tmp[tmp.size()-1] = nums[j];
                    // }else
                    // {
                    //     tmp.push_back(nums[j]);
                    // }
                        
                    dp[i] = max(dp[i], dp[j] +1);
                }  
            }
            // tmp.push_back(nums[i]);
            // result.push_back(tmp);

            // print test
            // for(const auto & row :tmp){
                // cout<< row << ' ';
            // }
            // cout<< endl;

            max_length = max(max_length,dp[i]);
        }
        return max_length;
    }
};
// @lc code=end

