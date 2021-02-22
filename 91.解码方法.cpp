/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    //空间复杂度为O(n),可以压缩成常数级的表示
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<int> dp(s.size()+1);
        // dp[0]=1 实际上是根据dp[i]=dp[i-1]推导出来的，无实际意义。
        dp[0]=1 ,dp[1]=1;
        for(int i = 1; i<s.size(); ++i){
            if (s[i]=='0'){
                //10/20的情况
                if (s[i-1]=='1'||s[i-1]=='2'){
                    dp[i+1] = dp[i-1]; //dp 比s大一位
                }else{
                    return 0;
                }
            }else
            {   //10~26
                if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')){
                    dp[i+1] = dp[i] + dp[i-1];
                }
                else //其他情况维持不变
                {
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

