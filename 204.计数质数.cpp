/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> prime(n,true);
        //埃氏筛,标记质数的倍数为合数
        int ans = 0;
        for(int i = 2; i<n; ++i){
            if(prime[i]){
                ans +=1;
                //从2i开始标记。
                //如果从i*i标记，那么注意越界
                // long long j = i*i
                for(int j = 2*i; j<n ; j+=i){
                    prime[j] = false;
                }
            }
        }
        return ans;

    }
};
// @lc code=end

