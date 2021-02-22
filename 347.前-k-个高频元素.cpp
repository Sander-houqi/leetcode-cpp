/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        int max_count= 0 ;
        // 次数map
        for(const int & num : nums){
            max_count = max(max_count, ++counts[num]);
        }

        // 桶排序
        vector<vector<int>> bucket(max_count+1);
        //  桶的频率作为数组下标，数组元素作为值
        for(const auto & p : counts){
            bucket[p.second].push_back(p.first);
        }

        //倒序遍历
        vector<int> ans;
        for(int i = max_count; i>=0 && ans.size()< k; --i){
            for(const int & num : bucket[i]){
                ans.push_back(num);
                if (ans.size()==k) break;
            }
        }

        return ans;
    }
};
// @lc code=end

