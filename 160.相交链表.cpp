/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA , *l2 = headB;

        // A遍历完指向B的头结点，B遍历完指向A的头结点
        // 如果相交，走过的路程都是相同的，所以刚好到达相交点
        while (l1!=l2)
        {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }

        return l1;
        
    }
};
// @lc code=end

