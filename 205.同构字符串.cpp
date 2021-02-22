/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //两个哈希表，用来映射第一次出现的位置
        //ascii标准字符有128，扩充后的有256个字符，包含运算符，拉丁文；
        vector<int> s_ind(256,-1),t_ind(256,-1);
        for(int i=0; i<s.length();++i){
            if(s_ind[s[i]]!=t_ind[t[i]]){
                return false;
            }
            // 注意要避开初始化的值，如果初始化0，那么此处可以写为i+1;
            s_ind[s[i]] = t_ind[t[i]] = i;
        }
        return true;
    }
};
// @lc code=end

