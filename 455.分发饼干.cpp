/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child = 0 , cookie = 0;
        while(child < g.size() && cookie < s.size()){
            // 最小的孩子分配最小的饼干
            if (g[child]<=s[cookie]){
                ++child;
            }
            ++cookie;
        }
        return child;

    }
};

// @lc code=end

