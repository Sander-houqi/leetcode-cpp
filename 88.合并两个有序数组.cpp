/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // pos 为 m +n -1 , m-- 先赋值后减去1，n-- 先赋值后减去1
        // nums1 取值范围有m--，所以不会超边界
        int pos  = m-- + n-- -1;
        while(m>=0 && n>=0){
            nums1[pos--] = nums1[m] > nums2[n]? nums1[m--]: nums2[n--];
        }

        while (n>=0)
        {
            nums1[pos--] = nums2[n--];
        }

    }
};
// @lc code=end

