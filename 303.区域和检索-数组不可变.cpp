/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

#include<vector>
#include<numeric>
using namespace std;


// @lc code=start
// class NumArray {
//     vector<int> psum;

// public:
//     //构造函数初始化
//     NumArray(vector<int>& nums): psum(nums.size()+1 , 0) {
//         //因为是从0开始，所以最后result要加1
//         partial_sum(nums.begin(),nums.end(),psum.begin()+1);
//     }
    
//     int sumRange(int i, int j) {
//         return psum[j+1]-psum[i];
//     }
// };


class NumArray {
    vector<int> psum;

public:
    //构造函数初始化
    NumArray(vector<int>& nums){
        //resize 确定vector的大小，并初始化,否则只能用push_back
        psum.resize(nums.size()+1,0);
        for(int i=1; i<=nums.size();++i){
            psum[i] = psum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return psum[j+1]-psum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

