/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include<string>
#include<unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int max_l = 0;
        //左指针
        int left = 0;
        //滑动窗口的值
        unordered_set<char> hashset;

        // i 表示遍历右指针
        for(int i =0 ; i < s.size(); ++i){
            while(hashset.find(s[i]) != hashset.end()){
                //如果右指针中元素在hashset中存在,从滑动窗口左侧开始移除,直到hashset不存在当前重复元素为止
                hashset.erase(s[left]);
                left++;
            }
            max_l = max(max_l, i-left+1);
            hashset.insert(s[i]);
        }
        return max_l;
    }
};
// @lc code=end

