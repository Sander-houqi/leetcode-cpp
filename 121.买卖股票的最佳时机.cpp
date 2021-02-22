/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<vector>
#include<limits.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX, maxprofit=0;
        for(int price : prices){
            minprice = min(price,minprice);
            maxprofit = max(maxprofit,price-minprice);
        }
        return maxprofit;

    }
};
// @lc code=end

