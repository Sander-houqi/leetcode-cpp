/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        if(s.length()==0) return 0;

        int c = 0 , i = s.length()-1;

        //从后向前遍历，排除最后的空格
        while(i>=0 && s[i]==' ')
        {
            --i;
        }

        while (i>=0 && s[i--]!=' ')
        {
            ++c;
        }
        
        return c;
    }
};
// @lc code=end

