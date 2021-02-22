/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int l = 0 , r = nums.size()-1, target = nums.size() -k ;
        while(l<=r){
            int partition = quickSelection(nums,l,r);
            if (partition==target){
                return nums[target];
            }else if (partition<target){
                l = partition+1;
            }else
            {
                r = partition-1;
            }
        }
        return -1;

    }

    int quickSelection(vector<int>& nums, int l ,int r){
        int i = l+1, j = r;
        int pivot = nums[l];
        //这里边界条件很容易出错
        while(true){
            while(i <= j && nums[i]<=pivot){
                ++i;
            }
            while(i <= j && nums[j]>=pivot){
                --j;
            }
            if (i>j) break;

            swap(nums[i],nums[j]);
        }

        swap(nums[l],nums[j]);

        return j;

    }

    //  int quickSelection(vector<int>& nums, int l ,int r){
    //     int i = l+1, j = r;
    //     int pivot = nums[l];
    //     //这里边界条件很容易出错
    //     while(true){
    //         while(i < r && nums[i]<=pivot){
    //             ++i;
    //         }
    //         while(j > l  && nums[j]>=pivot){
    //             --j;
    //         }
    //         //>=
    //         if (i>=j) break;

    //         swap(nums[i],nums[j]);
    //     }

    //     swap(nums[l],nums[j]);

    //     return j;

    // }


    // int quickSelection(vector<int>& nums, int i ,int j){
    //     int pivot = j;
    //     pivot 为最后一个元素
    //     while(i<j){
    //         while(i < j && nums[i]<=nums[pivot]){
    //             ++i;
    //         }
    //         while(i < j && nums[j]>=nums[pivot]){
    //             --j;
    //         }
    //         swap(nums[i],nums[j]);
    //     }

    //     swap(nums[pivot],nums[i]);

    //     return j;

    // }
};
// @lc code=end

