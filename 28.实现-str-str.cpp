/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

//KMP算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = -1 , n = haystack.length() , p = needle.length();
        if(p==0) return 0;
        // 默认初始化-1，-1表示没有相同的最大前缀和后缀
        vector<int> next(p,-1);
        calNext(needle,next);
        //k表示字串的索引
        for(int i = 0; i<n; ++i){
            while (k>-1 && needle[k+1] != haystack[i])
            {   
                // 部分匹配，回溯
                k = next[k]; 
            }
            if(needle[k+1] == haystack[i]){
                ++k;
            }

            if(k==p-1){
                //匹配成功，返回匹配的位置
                return i-p+1;
            }
        }
        return -1;
    }

    //计算next数组，包含公共前后缀的最大长度
    void calNext(const string& needle, vector<int>& next){
        // p是前后缀的最大公共长度
        for(int j = 1 , p = -1; j < needle.length(); ++j){
            while(p > -1 && needle[p+1] != needle[j]){
                //如果不相等，则p回退，这个回退就有递归的意思在了。
                p = next[p];
            }
            if(needle[p+1] == needle[j]){
                //如果相同，则更新最大长度
                ++p;
            }
            next[j] = p;
        }
    }
};
// @lc code=end

