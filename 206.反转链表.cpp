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
    ListNode* reverseList(ListNode* head) {
        ListNode * pre = nullptr, *curr = head , *tmp = head;

        while (curr)
        {
            tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;
    }

    // 递归 
    // ListNode* reverseList(ListNode* head , ListNode* prev = nullptr){
    //     if(!head) return prev;

    //     ListNode *next = head->next;
    //     head->next = prev;
    //     return reverseList(next,head);
    // }


    //另一种只有head的递归
    //参考https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/
    // ListNode* reverseList(ListNode* head){
    //     if(!head || !head->next) return head;

    //     // new_head 是最后一个节点
    //     ListNode* new_head = reverseList(head->next);
    //     //反转指向
    //     head->next->next = head;
    //     //当前head指向断开，防止循环指向
    //     head->next = nullptr;
    //     return new_head;
    // }
};
// @lc code=end

