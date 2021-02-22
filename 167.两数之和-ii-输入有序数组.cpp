/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 输入序列有序，双指针或者二分查找
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 , r = numbers.size()-1 , sum;

        while(l<r){
            sum = numbers[l]+ numbers[r];
            if (sum == target) break;
            if (sum<target) ++l;
            else --r;
        }
        // 注意题目说明，下标不是从0开始
        return vector<int>{l+1,r+1};

    }
};
// @lc code=end

