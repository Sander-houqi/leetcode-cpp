/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum=0, count=0;
        //前缀和/出现次数
        unordered_map<int,int> hash;
        //前缀和为0出现一次，必须这样初始化
        //细节，这里需要预存前缀和为 0 的情况，会漏掉前几位就满足的情况
        //例如输入[1,1,0]，k = 2 如果没有这行代码，则会返回0,漏掉了1+1=2，和1+1+0=2的情况
        //输入：[3,1,1,0] k = 2时则不会漏掉
        hash[0]=1;
        for(int i: nums){
            psum +=i;
            //只需要看psum-k的次数
            count += hash[psum-k];
            ++hash[psum];
        }
        return count;

    }
};
// @lc code=end

