/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    //分治法，动态规划比较复杂略过。
    vector<int> diffWaysToCompute(string input) {
        vector<int> ways;
        for(int i=0; i<input.length();++i){
            char c = input[i];
            if(c=='+' || c=='-' || c=='*'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(const int & l: left){
                    for(const int & r: right){
                        switch (c){
                        case '+': ways.push_back(l+r); break;
                        case '-': ways.push_back(l-r); break;
                        case '*': ways.push_back(l*r); break;
                        }
                    }
                }
            }
        }
        // 边界
        if(ways.empty()){
            //stoi 字符串转整数
            ways.push_back(stoi(input));
        }
        return ways;
    }
};
// @lc code=end

