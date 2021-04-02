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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


#include<vector>
using namespace std;

class Solution {
public:
    //递归
    //时空复杂度均为O(n)
/*     ListNode* reverseKGroup(ListNode* head, int k) {

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
    } */

    //迭代法
    //时间复杂度为O(n),空间复杂度为O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;

        while(head){
            ListNode* tail = pre;
            //剩余长度小于k直接返回
            for(int i = 0; i < k; ++i){
                //因为pre是head的前置节点，所以先下一个再判断
                tail = tail->next;
                if(!tail) return dummy->next;
            }

            ListNode *next = tail->next;
            auto result = myReverse(head,tail);
            head = result.first;
            tail = result.second;

            //拼接
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }

    //reverse 返回新的头和尾
    pair<ListNode*,ListNode*> myReverse(ListNode* head, ListNode* tail){

        ListNode *prev = nullptr;
        ListNode *cur = head, *tmp;
        //注意这里的判断条件
        while (prev!=tail)
        {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return {tail,head};
    }
};
// @lc code=end

