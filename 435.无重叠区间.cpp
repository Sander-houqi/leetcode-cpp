/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return 0 ;
        }
        int n = intervals.size();
        //[] 表示匿名函数
        sort(intervals.begin(),intervals.end(),[](vector<int> a ,vector<int> b){
            return a[1] < b[1];
        });
        // intervals[0][1]第一个vector的右侧边界
        int total = 0, prev = intervals[0][1];
        for (int i = 1; i < n ; ++i){
            if (intervals[i][0]<prev){
                ++total;
            }else{
                prev = intervals[i][1];
            }
        }
        
        return total;

    }
};
// @lc code=end

