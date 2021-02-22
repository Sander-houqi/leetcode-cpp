/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chucks = 0, max_num = 0;
        for(int i=0; i<arr.size();++i){
            max_num = max(arr[i],max_num);
            // 利用了索引和最大值之前的关系
            if (max_num==i){
                chucks+=1;
            }
        }
        return chucks;
    }
};
// @lc code=end

