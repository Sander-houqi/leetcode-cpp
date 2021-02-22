/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 非递归
    // ListNode* reverseList(ListNode* head) {
    //     ListNode * pre = nullptr, *curr = head , *tmp = head;

    //     while (curr)
    //     {
    //         tmp = curr->next;
    //         curr->next = pre;
    //         pre = curr;
    //         curr = tmp;
    //     }
    //     return pre;
    // }

    // 递归 
    ListNode * reverseList(ListNode* head , ListNode* prev = nullptr){
        if(!head) return prev;

        ListNode *next = head->next;
        head->next = prev;
        return reverseList(next,head);
    }
};
// @lc code=end

