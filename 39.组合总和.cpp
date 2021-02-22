/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    // 模型复杂度是O(n*2^n),n个位置，每个位置可以有选和不选两种情况
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return {};
        // 排序是为了剪枝
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return res;
    }

    void backtrack(vector<int>& candidates, int begin, int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        
        // i 从begin开始，避免得到重复的结果集
        for(int i = begin; i<candidates.size(); ++i){
            // 剪枝，如果叶子节点不是负数，则继续遍历
            if(target-candidates[i]>=0){
                path.push_back(candidates[i]);
                backtrack(candidates,i,target-candidates[i]);
                //回溯重置
                path.pop_back();
            }
        }
    }
};
// @lc code=end

