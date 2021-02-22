/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */
#include<vector>
#include<stdlib.h>
#include<numeric>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> sums;
public:
    Solution(vector<int>& w): sums(std::move(w)) {
        // 前缀和
        partial_sum(sums.begin(),sums.end(),sums.begin());
    }
    
    int pickIndex() {
        // back() 返回vecotr末尾元素的引用
        int pos = (rand() % sums.back()) +1;
        // 二分查找寻找左侧边界
        return lower_bound(sums.begin(),sums.end(),pos) -sums.begin();

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

