/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // 0/1背包状态压缩需要逆序
        for(const auto & s : strs){
            auto [count0,count1] = count(s);
            for(int i = m; i >= count0;--i){
                for(int j=n; j >= count1;--j){
                    //装和不装,已经缩减了维度
                    dp[i][j] = max(dp[i][j],dp[i-count0][j-count1]+1);
                }
            }
        }
        return dp[m][n];
        
    }

    pair<int,int> count(const string& str){
        int count0 = 0 , count1= 0;
        for(const auto & c : str){
            if(c =='0'){
                ++count0;
            }else
            {
                ++count1;
            }
        }
        return make_pair(count0,count1);
    }
};
// @lc code=end

