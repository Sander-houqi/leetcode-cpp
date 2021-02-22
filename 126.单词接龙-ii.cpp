/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        // 无序set,或者可以建立一个访问过的集合，就不用后续移除了。
        unordered_set<string> dict;

        for(const auto& w : wordList){
            dict.insert(w);
        }
        // 判断endword是否存在
        if(!dict.count(endWord)){
            return ans;
        }

        // 去除首尾字符串
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_set<string> q1{beginWord},q2{endWord};
        // 图的邻接表
        unordered_map<string, vector<string>> next;
        // 是否反向搜索
        bool reversed = false, found = false;
        // BFS 建立邻接表
        while(!q1.empty()){
            // q 临时set
            unordered_set<string> q;
            // set中的每个单词
            for (const auto & w:q1) {
                string s = w;
                // 遍历字符
                for(size_t i= 0; i<s.size(); ++i){
                    char ch = s[i];
                    // 26个字母
                    for(int j = 0; j< 26; ++j){
                        // 替换为字母
                        s[i] = j + 'a';
                        //如果替换后的单词存在q2中,加入到邻接表中
                        if(q2.count(s)){
                            // 如果reversed true 则s的临界边是w，否则相反
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            //找到最后的单词
                            found = true;
                        }
                        if(dict.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            //如果单词存在在给定的单词表中，插入q中
                            q.insert(s);
                        }
                    //回退
                    s[i] = ch;
                    }
                }
            }

            if (found) break;

            // 移除已经加入加入邻接表的节点
            for(const auto & w :q){
                dict.erase(w);
            }

            // 继续前向搜索，保证q1是最小的节点集合。
            if(q.size()<q2.size()){
                q1=q;
            }else
            {   // 反向搜索
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
            
        }

        if (found){
            vector<string> path = {beginWord};
            dfs(beginWord,endWord,next,path,ans);
        }
        
        return ans;
    }

    void dfs(const string& src, const string& dst, unordered_map<string ,vector<string>> & next, vector<string>& path ,vector<vector<string>> &ans){

        if (src ==dst){
            ans.push_back(path);
            return;
        }

        for(const auto &s : next[src]){
            path.push_back(s);
            // 如果搜素到直接从上面return，否则回溯到当前节点。
            dfs(s,dst,next,path,ans);
            path.pop_back();
        }
    }
};
// @lc code=end

