/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==nullptr) return nullptr;
        
        ListNode * cur = head , *aft = head->next;

        while (cur && aft)
        {
            if(cur->val == aft->val){
                aft = aft->next;
                cur->next = aft;
            }else
            {
                cur = cur->next;
                aft = aft->next;
            }
        }

        return head;
        
    }
};
// @lc code=end

