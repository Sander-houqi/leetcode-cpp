/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return x;
        int l=1 , r = x, mid , sqrt ;
        while (l<=r)
        {
            mid = l + (r-l) / 2 ;
            sqrt = x / mid ;
            if (sqrt==mid){
                return mid;
            }else if (mid > sqrt)
            {
                r = mid - 1 ;
            }else
            {
                l = mid + 1 ;
            }
        }
        //平方根一定是r，l这个时候必定大于r
        return r;
    }
};
// @lc code=end

