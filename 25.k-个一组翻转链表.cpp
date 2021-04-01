/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
class Solution {
public:
    //递归
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head) return head;

        ListNode* tail = head;
        for(int i = 0; i < k; ++i){
            //如果后续节点不足k个，直接返回
            if(!tail) return head;
            tail = tail->next;
        }

        //reverse k 个节点
        ListNode *pre = nullptr, *cur = head, *tmp=head;
        while(cur!=tail)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        //递归后续节点
        head->next = reverseKGroup(cur,k);
        //返回反转后的头节点
        return pre;
    }
};
// @lc code=end

