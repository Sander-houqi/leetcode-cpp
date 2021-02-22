/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // bool isPowerOfFour(int n) {
    //     return fmod(log10(n)/log10(4),1)==0;
    // }

    // bool isPowerOfFour(int n) {
    //     // 先判断是不是2的幂 (n & (n-1)) 如果是0，则是2的幂
    //     // 然后判断是偶数幂还是奇数幂，如果从0位开始算，是偶数幂那么就是4的幂
    //     // 那么与101010..10 & 会得到0,由于4^16>2^31-1,所以16进制的16位10表示如下
    //     return n > 0 && !(n & (n-1)) && !(n & 0xaaaaaaaa);
    // }

    bool isPowerOfFour(int n){
        if (n==0) return 0;
        while (n%4==0)
        {
            n /= 4;
        }
        return n==1;
    }
};
// @lc code=end

