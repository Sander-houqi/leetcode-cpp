/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 双指针模拟加法进位
    string addStrings(string num1, string num2) {
        // -1 字符串末尾有一个空字符\0
        int i = num1.length()-1 , j = num2.length()-1, add = 0;
        string ans = "";
        // 逆序遍历，位数短的补0
        while (i>=0 || j>=0 || add !=0)
        {
            int x = i >=0 ? num1[i]-'0' : 0;
            int y = j >=0 ? num2[j]-'0' : 0;
            int result = x + y+ add ;
            // int to char
            ans.push_back('0'+result%10);
            add = result/10;
            i-=1;
            j-=1;
        }
        // 翻转
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};
// @lc code=end

