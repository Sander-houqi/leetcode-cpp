/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include<vector>
using namespace std;

// @lc code=start
class NumMatrix {
    //位置（0，0）到（i，j）的数字和
    vector<vector<int>> intergral;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        //构造函数也可加入return
        if(matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        intergral = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                //前缀和扩展到二位，即积分图，计算如下当前坐标+上方长方形的数字和+左边长方形的数字和-重合面积的数字和
                intergral[i][j] = matrix[i-1][j-1]+ intergral[i-1][j] + intergral[i][j-1] - intergral[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //给定两个点构成的长方形的位置和
        //因为求和包含[0][0]所以要注意加1
        //总面积减去上面和左侧两个矩形的面积+被覆盖两次的左上方矩形
        return intergral[row2+1][col2+1] - intergral[row2+1][col1] - intergral[row1][col2+1] + intergral[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

