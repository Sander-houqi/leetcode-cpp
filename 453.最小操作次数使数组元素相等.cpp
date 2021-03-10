/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */


#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    //n-1个加1等价于只有一个元素减1，并且由于只能+1，所以最后相等的数一定为最小值
    int minMoves(vector<int>& nums) {

        int min_num = INT_MAX;

        //最小值
        for(auto & num: nums){
            min_num = min(num,min_num);
        }

        int ans = 0;

        for(auto & num: nums){
            ans += num - min_num;
        }

        return ans;
    }
};
// @lc code=end

