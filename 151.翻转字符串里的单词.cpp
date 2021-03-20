/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // 我是官方题解搬运工QAQ/^-^
    string reverseWords(string s) {

        reverse(s.begin(),s.end());
        
        //新的序列的索引
        int idx = 0;
        //下面两种循环皆可以
        for(int i = 0; i < s.size(); ++i){
        // int i = 0;
        // while(i < s.size()){
            if(s[i]!=' ')
            {   
                //单词开始添加一个空格，反转后就刚好隔开
                if(idx!=0) s[idx++]=' ';

                //遍历单词末尾
                int j = i;
                while (j < s.size() && s[j]!=' ')
                {
                    s[idx++] = s[j++];
                }

                //反转单词
                reverse(s.begin() + idx - (j-i) , s.begin() + idx);
                
                //直接变更索引，跳过当前单词
                i = j;

            }
            // while 循环要自增
            // ++i;
            
        }
        //删除多余字符，因为如果有多个空格，而填充的时候只有一个空格，所以是会有多余的，删除后续即可
        s.erase(s.begin()+idx,s.end());
        return s;

    }
};
// @lc code=end

