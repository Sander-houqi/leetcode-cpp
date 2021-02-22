/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

#include<string>
#include<cstdio>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s,i);

    }

    long parseExpr(const string& s , int& i){
        char op ='+';
        long left = 0, right = 0;
        while (i<s.length())
        {   
            if(s[i] != ' '){
                //转整型，同时i会自增到运算符处
                long n = parseNum(s,i);
                // right 用来暂存前一个+-运算符的结果，如果遇到*/直接计算
                switch (op){
                    case '+': left += right; right = n; break;
                    case '-': left += right; right = -n; break;
                    case '*': right *= n; break;
                    case '/': right /= n; break;
                    default:  break;
                }
                if(i<s.length()){
                    op = s[i];
                }
            }
            ++i;
        }
        return left+right;
        
    }
    //字符串转long
    //int long要看编译器，在32位编译器的都是4字节，64位系统long是8字节64位，int是4字节32位。
    //必须用&i,引用i自增，那么调用的i也会改变
    long parseNum(const string& s , int &i){
        long n = 0;
        while (i<s.length() && isdigit(s[i]))
        {   
            n = n *10 + (s[i++] - '0');
        }
        return n;
    }

    
};
// @lc code=end

