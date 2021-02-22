/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include<vector>
#include<string>
#include<limits.h>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        if(n<2){
            return 0;
        }
        // 边界条件
        // if(k>=n/2){
        //     return maxProfitUnlimited(prices);
        // }

        // buy[j] 表示在第j次买入的最大收益，sell[j]表示第j次卖出的最大收益。
        vector<int> buy(k+1,INT_MIN), sell(k+1,0);
        for(int i =0; i< n; ++i){
            for(int j=1;j<=k; ++j){
                //buy[j]因为压缩实际是存储的是buy[i-1][j]的值,持有不动
                buy[j] = max(buy[j],sell[j-1]-prices[i]);
                sell[j] = max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k];
        
    }

    int maxProfitUnlimited(vector<int> & prices){
        int maxProfit = 0;
        for(int i = 1; i < prices.size();++i){
            if(prices[i]>prices[i-1]){
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};

int main(){
    int k = 3;
    vector<int> nums{3,2,6,5,0,3};
    int max_Prof = Solution().maxProfit(k,nums);
    cout<< max_Prof<<endl;
    return 0;

}
// @lc code=end

