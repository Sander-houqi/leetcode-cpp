/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

#include<vector>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        // 素数分解的和，因为不在乎顺序，所以根号
        int h = sqrt(n);
        for(int i=2; i<=n; ++i){
            dp[i]=i;
            //dp[i]表示通过复制粘贴得到i个字符最少需要多少个操作数
            for(int j=2; j<=h;++j){
                if(i%j==0){
                    //素数两个因子的和
                    dp[i]=dp[j] + dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

// int main(){
//     int n = 2;
//     int result = Solution().minSteps(n);
//     cout<< result<< endl;
//     return 0;
// }
// @lc code=end

