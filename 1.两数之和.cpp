/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for (int i = 0 ; i< nums.size();++i ){
            auto it = hashtable.find(target-nums[i]);
            //it 是iterator 迭代器类型
            if (it != hashtable.end()){
                return {it->second,i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


// int main()
// {   

//     int target = 9;
//     vector<int> nums = {2,7,11,15};
//     vector<int> ret = Solution().twoSum(nums, target);
//     for (auto i = ret.begin(); i != ret.end(); ++i)
//         std::cout << *i << ' ';
//     return 0;
// }
// @lc code=end

