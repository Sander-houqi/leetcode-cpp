/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 竖式直接相乘
    string multiply(string num1, string num2) {
        // 0 单独处理
        if(num1 == "0" ||  num2 == "0"){
            return "0";
        }

        int m = num1.size() , n = num2.size();
        vector<int> ansArr(m+n, 0);

        for(int i = m-1; i>=0; --i){
            // at 和 [] 取值是相同的，只不过at 会进行越界检查
            int x = num1.at(i) -'0';
            for(int j = n-1; j>=0; --j){
                int y = num2.at(j) - '0';
                //关键步骤，模拟竖式乘法总结的规律，详见leetcode题解 https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
                ansArr[i+j+1] += x*y;
            }
        }

        // 处理进位,超过10的进位到下一位
        for(int i = m+n-1; i>0; --i){
            ansArr[i-1] += ansArr[i]/10;
            ansArr[i] %= 10;
        }

        //去除前缀0，并转换成字符串
        string ans;
        for(int i =0; i<ansArr.size(); ++i){
            if(i==0 && ansArr[i]==0 ) continue;
            ans.push_back(ansArr[i]+'0');
        }

        return ans;
    }
};
// @lc code=end

