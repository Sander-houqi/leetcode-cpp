/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution{
public:
    vector<int> direction{-1,0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size() , n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        bool find = false;
        // 循环变量i,j一定要初始化，否则可能产生意想不到的结果。
        for(int i=0; i < m; ++i){
            for(int j=0; j < n; ++j){
                backtracking(board,word,visited,find,0,i,j);
            }
        }
        return find;

    }

    void backtracking(vector<vector<char>>& board, string & word, vector<vector<bool>> & visited, bool& find, int pos , int i , int j){
        // 边界
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        // 是否访问过，找到，搜素不匹配
        if(visited[i][j] || find || board[i][j] != word[pos]) return;

        if(pos==word.size()-1){
            find = true;
            return;
        }
        visited[i][j]=true;
        int x,y;
        for(int k = 0; k< 4;++k){
            x = i + direction[k] , y = j + direction[k+1];
            backtracking(board,word,visited,find,pos+1,x,y);
        }
        visited[i][j]=false;
    }

};
// @lc code=end

