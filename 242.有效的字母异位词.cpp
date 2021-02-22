/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        vector<int> hash(26,0);

        // 用hash 26个字母存储所有的次数
        for(int i =0; i<s.length();++i){
            ++hash[s[i]-'a'];
            --hash[t[i]-'a'];
        }
        // 如果还存在不为0的值，那么包含的字符肯定不同。
        for(int i =0; i<26; ++i){
            if(hash[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

