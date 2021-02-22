/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<stdlib.h> 
using namespace std;

// struct 默认访问权限是public, class 默认访问权限是private
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0) , next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
ListNode *head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head(head) {

    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = 2;
        ListNode* node = head->next;
        int ans = head->val;
        while (node)
        {   
            //蓄水池算法，以1/i的概率选择当前值
            if ((rand() % i) ==0){
                ans = node->val;
            }
            ++i;
            node = node->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

