/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //int使用int()初始化，初值为0，不是随机值。
        unordered_map<int,int> hash;
        int ans = 0;
        for(const string & word: words){
            int mask = 0 ,size = word.size();
            // 二进制操作是为了减少比较是否含有重复字符。
            for(const char & c : word){
                // |的时候会转换为二进制操作，最后映射到26个字母。
                mask |= 1 << (c-'a');
            }
            // 相同掩码可能会对应不同的单词，所以要取最大的。
            hash[mask] = max(hash[mask],size);
            for(const auto & [key_mask,key_len] : hash){
                //如果位与为0，则无重复字符
                if(!(mask&key_mask)){
                    ans = max(ans,size*key_len);
                }
            }

        }
        return ans;
    }
};
// @lc code=end

