/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m  = s.size(), n = p.size();
        //dp 表示s的前i个能否被p的前j个匹配
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        //都是空串，可以匹配
        dp[0][0] = true;
        //边界，如果s为空,p要是匹配只能是*结尾，i-2就是干掉一个字符，即范围为[0,i-3]
        for(int i =1; i<=n; ++i){
            if(p[i-1]=='*'){
                dp[0][i] = dp[0][i-2];
            }
        }

        for(int i=1; i<=m;++i){
            for(int j=1; j<=n;++j){
                //最后一个字符可以匹配上
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                //没有匹配上看是否是*
                }else if (p[j-1]=='*'){
                    //满足条件，看前面子问题是否匹配
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){
                        //dp[i-1][j] 多个字符匹配；aabcc aabc*
                        //dp[i][j-1] 单个字符匹配；aabc aabc*
                        //dp[i][j-2] 没有字符匹配；aabc aabcc*
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    }else{
                        //不满足直接干掉两个字符,考察是否可以
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[m][n];

    }
};
// @lc code=end

