/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> chars(128,0);
        vector<bool> flag(128,false);

        //统计t字符的情况
        //chars表示目前缺少的字符，flag表示t中是否存在某字符
        for(int i=0 ; i< t.size(); ++i){
            flag[t[i]] = true;
            ++chars[t[i]];
        }
        //cnt 滑动窗口的在t中字符数量
        int cnt = 0 , l = 0 , min_l= 0, min_size = s.size() + 1;
        for (int r = 0 ; r < s.size(); ++r){
            if (flag[s[r]]){
                if (--chars[s[r]]>=0){
                    ++cnt;
                }
                //如果已经包含全部字符，尝试将左边的指针右移
                while (cnt==t.size())
                {
                    if (r-l+1 < min_size){
                        min_l = l;
                        min_size = r -l +1;
                    }
                    //如果满足条件，字符数量要减去1
                    if (flag[s[l]] && ++chars[s[l]] > 0){
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l,min_size);
    }
};
// @lc code=end

