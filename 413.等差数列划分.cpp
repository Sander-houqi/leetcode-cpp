/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */
#include <vector>
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n<3) return 0 ;
        vector<int> dp(n,0);
        // 描述中小于3个的不是等差数组
        // dp[i] 表示以i结尾的等差数列的个数
        for(int i = 2 ; i < n ; ++i){
            if (A[i]-A[i-1] == A[i-1] - A[i-2]){
                dp[i] = dp[i-1]+1;
            }
        }
        return accumulate(dp.begin(),dp.end(),0);

    }
};
// @lc code=end

