/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    // 假设最简单的情况 000111, 先遍历, 前面的 0 的数量为 curr = 3, 遍历到 1 时, pre = curr 赋值为 3, 
    //然后 curr = 1 表示现在 1 的个数, 只要 curr <= pre, 比如 curr = 1, 那么可以组成 01; curr = 2, 可以组成 0011,
    // curr = 3, 组成 000111, 直到出现下一次 0, 然后那么 prev 就是 1 的个数, curr 表示 0001110...这个 1 后面 0 的个数, 不断重复迭代下去

    //或者换种理解方式，实际还是看连续的0或者1的个数最小,或者可以求出连续0和1的个数，然后相邻最小个数然后相加得到最后的结果。
    int countBinarySubstrings(string s) {
        int pre=0, cur=1, count=0;
        for(int i=1; i<s.length();++i){
            if(s[i]==s[i-1]){
                ++cur;
            }else
            {
                pre = cur;
                cur = 1;
            }
            if(pre>=cur){
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

