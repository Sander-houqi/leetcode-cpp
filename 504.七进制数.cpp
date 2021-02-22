/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        //注意负号
        bool is_neg = num<0;
        if(is_neg) num = -num;
        string ans;
        // 进制转换都一样，除7取余法
        while (num)
        {
            int a = num / 7 , b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        return is_neg? "-" + ans: ans;
        
    }
};
// @lc code=end

