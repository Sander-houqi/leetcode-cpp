/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /*   // 回溯
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k,0);
        int count = 0;
        //排列组合从1开始
        backtracking(ans,comb,count,1,n,k);
        return ans;

    }

    void backtracking(vector<vector<int>>& ans , vector<int>& comb , int& count ,int pos, int n , int k){
        if(count==k){
            ans.push_back(comb);
            return;
        }
        for(int i=pos; i<=n; ++i){
            //先修改在++
            comb[count++] = i;
            backtracking(ans,comb,count,i+1,n,k);
            --count;
        }
    } */

     vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        //直接使用vector,不使用索引。
        vector<int> comb;
        //排列组合从1开始
        backtracking(ans,comb,1,n,k);
        return ans;

    }

    void backtracking(vector<vector<int>>& ans , vector<int>& comb , int pos, int n , int k){
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }
        for(int i=pos; i<=n; ++i){
            comb.push_back(i);
            backtracking(ans,comb,i+1,n,k);
            comb.pop_back();
        }
    }   

};
// @lc code=end

