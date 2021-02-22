/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include<vector>
#include<string>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 逐个旋转，注意坐标规律matrix[ii][j] = matrix[n-j-1][i] 以此类推
        for(int i=0; i<n/2; ++i){
            //两个边界条件都可
            // for(int j=i ; j< n-i-1; ++j){
                // cout<< i <<j << endl;
            //融合边长为奇偶后的边界
            for(int j=0 ; j< (n+1)/2; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
};
// @lc code=end

