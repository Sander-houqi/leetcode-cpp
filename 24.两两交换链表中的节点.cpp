/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    // 递归
    // ListNode* swapPairs(ListNode* head) {
            //没有节点或者1个节点则返回
    //     if(head==nullptr || head->next== nullptr){
    //         return head;
    //     }

    //     ListNode *tmp = head->next;
    //     head->next = swapPairs(tmp->next);
    //     tmp->next = head;
    //     return tmp;
    // }

    // 非递归
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0,head) , *tmp = dummyNode;
        while (tmp->next !=nullptr && tmp->next->next != nullptr)
        {
            ListNode* node1 = tmp->next;
            ListNode* node2 = tmp->next->next;
            // 画图会好理解一些,见listNode官方答案
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        return dummyNode->next;
    }
};
// @lc code=end

