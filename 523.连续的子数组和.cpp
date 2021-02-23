/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //前缀和+取模
    // a % c = b % c 则 (a - b) % c = 0
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> hash;
        hash.insert({0,-1});

        int sum =0;
        for(int i=0; i< nums.size(); ++i){
            sum += nums[i];
            if(k!=0){
                sum = sum % k;
            }
            if(hash.count(sum)){
                if(i-hash[sum]>1){
                    return true;
                }
            }else{
                hash.insert({sum,i});
            }
        }
        return false;
    }
};
// @lc code=end

