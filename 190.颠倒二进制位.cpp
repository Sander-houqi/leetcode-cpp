/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

#include<stdint.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // uint32_t是别名，即typedef unsigned int,表示无符号整型
    uint32_t reverseBits(uint32_t n) {
        //初值位最后一次会被移位去掉
        uint32_t ans = 0;
        for(int i=0; i<32; ++i){
            //左移一位,为了二进制拼接到正确的位置
            ans <<= 1;
            //获得最后一位
            ans += n&1;
            n >>= 1;
        }
        return ans;
        
    }
};
// @lc code=end

