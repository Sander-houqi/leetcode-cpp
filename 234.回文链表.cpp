/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/* struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode* next): val(x),next(next){}
}; */

#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || ! head->next) return true;

        ListNode *slow = head , *fast = head;
        //找到中间节点，后半段反转
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * p1 = head;
        //奇数个节点，中间部分看做前半部分
        ListNode * p2 = reverseList(slow->next);
        while (p2)
        {
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    ListNode * reverseList(ListNode *head){
        ListNode *prev = nullptr, *curr = head, *tmp;
        while (curr)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        return prev;
    }
};
// @lc code=end

