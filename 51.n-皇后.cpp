/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:

    // 时间复杂度O(n!),n是棋盘的行/列，n*(n-1).... ,第一个皇后有n中选择，第二个最多有n-1中选择
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        if(n==0) return ans;
        // 初始化棋盘方格
        vector<string> board(n,string(n,'.'));
        // 初始化列访问数组，主对角线访问数组，副对角线访问数组，不需要行访问数组，因为是通过行进行遍历的
        // 主对角线和副对角线都有2n-1个
        // 性质：主对角线上的差值一定，副对角线和一定
        vector<bool> cols(n,false), ldiag(2*n-1,false), rdiag(2*n-1,false);
        backtracking(ans,board,cols,ldiag,rdiag,0,n);
        return ans;

    }
    void backtracking(vector<vector<string>>& ans ,vector<string>& board, vector<bool>& cols, vector<bool>& ldiag, vector<bool>& rdiag, int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        // 每一列
        for(int i = 0; i < n ; ++i){
            // https://leetcode-cn.com/problems/n-queens/solution/gen-ju-di-46-ti-quan-pai-lie-de-hui-su-suan-fa-si-/ (i-row+n-1)可见此篇解析
            //i-row对角线差+(n-1)映射到(0~2n-1)
            //i+row对角线和
            if (cols[i] || ldiag[i-row+n-1] || rdiag[i+row] ) continue;
            board[row][i]='Q';
            cols[i]= ldiag[i-row+n-1]=rdiag[i+row]=true;
            // 修改当前节点
            backtracking(ans,board,cols,ldiag,rdiag,row+1,n);
            // 回溯当前节点
            board[row][i]='.';
            cols[i]= ldiag[i-row+n-1]=rdiag[i+row]=false;
        }


    }
};
// @lc code=end

