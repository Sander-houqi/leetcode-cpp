/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

#include<vector>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // hash 有两种，unordered_set 和 unordered_map,带键值对；

        unordered_set<int> hash;
        for(const auto & num: nums){
            //调用构造函数，避免产生临时变量
            hash.emplace(num);
            // 将元素拷贝到容器中
            // hash.insert(num);
        }

        int ans=0;
        while(!hash.empty()){
            //随机获得一个元素
            int cur = *(hash.begin());
            hash.erase(cur);
            int pre = cur-1, aft = cur + 1;
            //移除所有连续序列
            while (hash.count(pre)){   
                //先移除后--
                hash.erase(pre--);
            }
            while(hash.count(aft)){
                //先移除后++
                hash.erase(aft++);
            }
            //因为都多加了一，所以要-1
            ans = max(ans,aft-pre-1);
        }
        return ans;
    }
};
// @lc code=end

