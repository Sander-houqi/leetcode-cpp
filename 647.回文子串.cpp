/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    // 中心扩展法
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i<s.length();++i){
            // 中心是奇数
            count += extendSubstrings(s,i,i);
            // 中心是偶数
            count += extendSubstrings(s,i,i+1);
        }
        return count;
    }

    int extendSubstrings(string s, int l ,int r){
        int count = 0;
        while (l>=0 && r<=s.length() && s[l]==s[r])
        {
            --l;
            ++r;
            ++count;
        }
        return count;
        
    }
};
// @lc code=end

