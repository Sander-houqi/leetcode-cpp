/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include<stdint.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0 ;
        while (n!=0)
        {
            ans+=1;
            n &= (n-1);
        }
        return ans;
        
    }
};
// @lc code=end

