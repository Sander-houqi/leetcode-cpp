/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

#include<vector>
#include<deque>
#include<queue>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        //默认大顶堆,默认先比较第一个值，然后在比较第二个值
        priority_queue<pair<int,int>> max_heap;// <高度，右端>
        int i = 0 ,len = buildings.size();
        int cur_x, cur_h;
        while (i<len || !max_heap.empty())
        {   
            //如果左侧坐标小于大顶堆的右侧坐标，大顶堆存放的是目前的天际线
            if(max_heap.empty() || i<len && buildings[i][0]<= max_heap.top().second){
                
                
                cur_x = buildings[i][0];
                //相同的起点左侧坐标加入优先队列中
                while (i<len && cur_x == buildings[i][0])
                {
                    max_heap.emplace(buildings[i][2],buildings[i][1]);
                    ++i;
                }
            // 左侧坐标大于堆顶的右侧坐标，说明无法覆盖到当前建筑
            }else{

                cur_x = max_heap.top().second;
                //右侧坐标小于堆顶的出堆
                while (!max_heap.empty() && cur_x >= max_heap.top().second)
                {
                    max_heap.pop();
                }
            }

            cur_h = (max_heap.empty()) ? 0 :max_heap.top().first;
            // 不能有连续相同高度
            if(ans.empty() || cur_h != ans.back()[1]){
                ans.push_back({cur_x,cur_h});
            }
            
        }
        
        return ans;

    }
};

// int main(int argc, char const *argv[])
// {
//     /* code */
//     vector<vector<int>> nums {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
//     vector<vector<int>> ans  = Solution().getSkyline(nums);
//     for ( const auto &row : ans ){
//         for ( const auto &s : row ) {
//             std::cout << s << ' ';
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

// @lc code=end

