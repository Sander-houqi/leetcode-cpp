/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include<vector>
#include<string>
#include<numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    //空间复杂度还可以进一步缩减。
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(),nums.end(),0);
        //判断奇偶,自动转换成二进制进行位运算
        if(sum & 1){
            return false;
        }
        int target = sum / 2 , n = nums.size();
        //dp[i][j] 表示0-i的正整数中是否存在和为j的选取方案
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;++i){
            dp[i][0] = true;
        }

        for(int i=1; i<=n;++i){
            // j= nums[i-1] 相当于做剪枝
            for(int j=nums[i-1]; j<=target;++j){
                dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

