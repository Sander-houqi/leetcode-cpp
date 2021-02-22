/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include<vector>
#include<string>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> indices;
        // 单调栈中从栈底到栈顶温度依次递减，存储的是indice，不是温度。
        for(int i=0; i<n; ++i){
            while (!indices.empty())
            {
                int top_ind = indices.top();
                //当日温度小于栈顶，break
                if(T[i] <= T[top_ind]){
                    break;
                }
                indices.pop();
                //栈顶对应元素的结果存储。
                ans[top_ind] = i - top_ind;
            }
            indices.push(i);
        }
        return ans;
    }
};
// @lc code=end

