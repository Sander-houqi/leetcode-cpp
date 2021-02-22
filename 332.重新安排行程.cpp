/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    //在连通图中寻找欧拉路径，半欧拉图（入度和出度的差为1）
    // 哈希map，其中值为优先队列，因为要字典序遍历，使用堆实现的，其中greater代表使用的是小顶堆，也就是降序排列，less是升序排列
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string> >> vec;

    vector<string> stk;

    //dfs,每次遍历删除一条边
    void dfs(const string& cur){
        //如果有边存在，就删除,遍历完当前节点所有节点才入栈
        while(vec.count(cur) && vec[cur].size()>0){
            string tmp = vec[cur].top();
            vec[cur].pop();
            //move相当于类型转换，左值转右值引用，可以减少不必要的拷贝，“abc”就属于常见的右值
            dfs(move(tmp));
        }
        stk.emplace_back(cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& it: tickets){
            vec[it[0]].emplace(it[1]);
        }

        dfs("JFK");
        
        //因为递归是从最后开始添加，所以要逆序
        reverse(stk.begin(),stk.end());

        return stk;

    }
};


// class Solution{
// public:
//     //使用哈希表+多重集合
//     vector<string> findItinerary(vector<vector<string>>& tickets){

//         vector<string> ans;
//         if(tickets.empty()) return ans;

//         unordered_map<string,multiset<string>> hash;
//         for(const auto & ticket: tickets){
//             hash[ticket[0]].emplace(ticket[1]);
//         }

//         stack<string> s;
//         s.push("JFK");

//         while (!s.empty())
//         {   
//             string next = s.top();
//             //如果最终没有到达点，当前节点所有节点都已经遍历过，加入结果集中
//             if(hash[next].empty()){
//                 ans.push_back(next);
//                 s.pop();    
//             }else
//             {   
//                 //把到达地加入到栈中,multiset本身是按照字典序排序的，所以begin就是字典序最小的
//                 s.push(*hash[next].begin());
//                 //hash中删除此条边
//                 hash[next].erase(hash[next].begin());
//             }
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
// @lc code=end

