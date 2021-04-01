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
    // 动态规划时间复杂度O(n^2，还可以使用二分查找优化)
/*     int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() , max_length = 0;
        if (n<=1) return n;
        vector<int> dp(n,0);
        // result 如果要获得最长递增序列，而不是只求长度
        // vector<vector<int>> result;
        for(int i =0; i < n; i++){
            //初始值是1;
            dp[i]=1;
            vector<int> tmp;
            //dp[j] 就代表nums[0...j]中以nums[j]结尾的最长递增子序列
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
    } */

    
    // 贪心+二分搜索
    // 这个得到的最长的递增子序列是最小字典序的序列
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size(), len = 1;

        if(n==0){
            return 0;
        }

        //dp[i] 表示长度为i的最长上升子序列的末尾元素的最小值
        //且通过反证法可证dp是一个单调递增的序列，就可以用二分查找
        //长度为i的末尾元素一定小于长度为i+1的末尾元素，这是由dp的定义决定的
        //证明参考https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
        //dp单调性证明，反证法证明：如果dp[j]>=dp[i],且j<i，从长度为i的子序列删除i-j个元素，序列长度变为j，且其末尾元素x必然小于d[i](因为是递增序列)，所以推出x<dp[i]<=dp[j],存在另外一个序列的末尾元素小于dp[j],矛盾。
        vector<int> dp(n+1,0);
        dp[len] = nums[0];

        for(int i = 1; i < n; ++i){
            // nums[i]如果大于末尾元素，直接追加
            if(nums[i] > dp[len]){
                dp[++len] = nums[i];
            }else{ // 否则在dp数组中找到一个比nums[i]小的，并更新dp的下一个位置
                int l = 1 , r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while(l<=r){
                    int mid = (l + r) >> 1;
                    if(dp[mid] < nums[i]){
                        pos = mid;
                        l = mid + 1; 
                    }else{
                        r = mid - 1;
                    }
                }
                dp[pos+1] = nums[i];
            }
        }
        return len;
    }
};
// @lc code=end

