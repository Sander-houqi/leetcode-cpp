/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include<vector>
#include<stdlib.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        quick_sort(nums,0, nums.size()-1);

        return nums;

    }

    int partition(vector<int>& nums, int low, int high){

        // rand privot
        int rand_i = rand() % (high-low + 1) + low;
        swap(nums[rand_i],nums[high]);
        
        int privot = nums[high];
        int i = low-1;
        for(int j = low; j < high; j++){
            if(nums[j] <= privot){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[++i],nums[high]);
        return i;
    }

    void quick_sort(vector<int>& nums, int l , int r){

        if(l < r){
            int index = partition(nums,l,r);
            quick_sort(nums,l,index-1);
            quick_sort(nums,index+1,r);
        }
    }


};
// @lc code=end

