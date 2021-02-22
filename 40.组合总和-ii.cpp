/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return {};
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return res;
    }

    void backtrack(vector<int>& candidates,int begin, int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i = begin; i < candidates.size(); ++i){
            if(i > begin && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target-candidates[i]>=0){
                path.push_back(candidates[i]);
                //不可以重复，所以是i+1
                backtrack(candidates,i+1,target-candidates[i]);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

