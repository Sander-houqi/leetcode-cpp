/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // bool isPowerOfThree(int n) {
    //     // 用对数
    //     return fmod(log10(n)/log10(3),1) == 0;
    // }


    bool isPowerOfThree(int n){
        if (n==0) return 0;
        while (n%3==0)
        {
            n /= 3;
        }
        return n==1;
    }
};
// @lc code=end

