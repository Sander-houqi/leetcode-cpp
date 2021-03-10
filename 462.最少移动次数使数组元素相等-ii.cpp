/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */


#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    //本质上是寻找中位数，因为中位数到N个点的移动距离最小
    //所以快速选择求第K大+ 中位数到N个点的移动距离
/*     int minMoves2(vector<int>& nums) {

        //直接排序时间复杂度O(nlogn)
        sort(nums.begin(),nums.end());

        int ans=0;
        for(int & num : nums){
            ans += abs(nums[nums.size()/2] - num);
        }
        return ans;
    } */

    int partition(vector<int>& nums, int l, int r){

        int privot = nums[r];
        int i = l -1;

        for(int j = l ; j < r; ++j){
            if(nums[j]<= privot){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[i+1],nums[r]);

        return i+1;
    }


    int quick_select(vector<int>& nums, int k){

        //需要寻找的是第k小，不是第k大，所以不需要n-k
        int n = nums.size(), target = k , l = 0, r = n-1;

        while(l<=r){
            int index = partition(nums,l,r);
            if(target==index){
                return nums[target];
            }else if(index < target){
                l = index + 1;
            }else{
                r = index - 1;
            }
        }
        return -1;
    }


    //用快速选择找第中位数
    int minMoves2(vector<int>& nums) {

        int median = quick_select(nums, nums.size()/2);
        int ans = 0;
        for(int & num : nums){
            ans += abs(median-num);
        }

        return ans;
    }

};
// @lc code=end

