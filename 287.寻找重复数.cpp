/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    // 用vector模拟hash，或者直接用unorder_set
    // 时间和空间复杂度都是O(n)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> map(n+1,0);
    //     for(const int & num: nums){
    //         ++map[num];

    //         if(map[num]>1){
    //             return num;
    //         }
    //     }
    //     return -1;
    // }


    //快慢指针，（这个真没想到）时间复杂度是O(n),空间复杂度O(1);
    // 前提是给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n),这样数组不会越界
    // 和求链表环的入口的题原理相同
    // int findDuplicate(vector<int>& nums){
    //     int fast = 0 , slow = 0;
    //     while (true)
    //     {   
    //         //将数组看做链表的表示
    //         //索引指向元素，元素指向索引
    //         //[1,3,4,2,2]  0->1->3->2->4->2->4....
    //         fast = nums[nums[fast]];
    //         slow = nums[slow];
    //         // 第一次相遇
    //         if(fast==slow){
    //             //快指针置为0
    //             fast =0;
    //             while (slow!=fast)
    //             {
    //                 fast = nums[fast];
    //                 slow = nums[slow];
    //             }
    //             return slow;
    //         }
    //     }
    // }

    // 和题442题是相同的
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i< nums.size(); ++i){
            int num = abs(nums[i]);
            //利用num的值来当索引，因为数组的范围在[1,n]之间
            if(nums[num-1]>0){
                nums[num-1] *= -1;
            }else
            {
                return num;
            }
        }

        return -1;
    }
};
// @lc code=end

