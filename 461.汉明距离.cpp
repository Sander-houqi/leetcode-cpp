/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        // ^异或，当且仅当位置不同的时候输出1；
        int diff = x^y , ans = 0;
        //判断一共有多少个1
        while (diff)
        {   
            //最后一位是否是1,
            ans += diff & 1;
            //右移一位
            diff >>= 1;
        }
        return ans;
        
    }
};
// @lc code=end

