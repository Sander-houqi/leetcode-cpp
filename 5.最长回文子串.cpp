/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:

    //参考leetcode官方题解
    string longestPalindrome(string s) {
        int n = s.size();
        //dp[i][j]表示s字符串从i到j是不是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        //字串长度为l+1
        for (int l = 0; l < n; ++l) {
            // 字串的起始位置i, j = i+l+1得到字串结束位置
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                // 特判，长度为1就是回文
                if (l == 0) {
                    dp[i][j] = 1;
                // 长度为2,如果i,j相等，就是回文
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                // 状态转移矩阵，子状态+两端字符是否相等
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                //更新最长字串
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

// @lc code=end

