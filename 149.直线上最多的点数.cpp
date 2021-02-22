/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    //[[1,1],[2,1],[2,2],[1,4],[3,3]]
    int maxPoints(vector<vector<int>>& points) {
        //<斜率，点数>
        // unordered_map<double,int> hash; 
        unordered_map<string,int> hash; 

        int ans = 0, same_x=1 ,same = 1;
        for(int i=0; i<points.size();++i){
            int same_x = 1, same = 1;
            for(int j=i+1; j<points.size();++j){
                // x相同j
                if(points[i][0]==points[j][0]){
                    ++same_x;
                    //重复元素
                    if(points[i][1]==points[j][1]){
                        ++same;
                    }
                }else
                {     
                    // 最后以后用例会溢出
                    // double dx = points[i][0]-points[j][0], dy= points[i][1]-points[j][1];
                    // ++hash[dy/dx];
                    //替换成最简分式是否相等
                    int dx = points[i][0]-points[j][0], dy= points[i][1]-points[j][1];
                    int tmp = gcd(dy,dx);
                    string key = to_string(dx / tmp) + "@" + to_string(dy / tmp);
                    ++hash[key];

                }
            }
            ans = max(ans,same_x);
            for(auto p: hash){
                ans = max(ans,same+p.second);
            }
            // 清空hash
            hash.clear();
        }
        return ans;
    }
private:
    // 最大公约数，辗转相除法
    int gcd(int a,int b){
        //负数取余，符号同前
        // -5/3 返回-1
        // 5/-3 返回1
        return (b == 0) ? a : gcd(b, a % b);
    }
};
// @lc code=end

