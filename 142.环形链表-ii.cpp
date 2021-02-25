/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include <cstddef>
using namespace std;

// @lc code=start
//  * Definition for singly-linked list.
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode *slow = head , *fast = head;
    //     // 判断环路是否存在
    //     do
    //     {
    //         if (!fast || !fast->next) return nullptr;
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     } while (fast!=slow);

    //     // 如果存在，相遇时fast移动到head,slow和fast每次前进一步，再次相遇时就为环节点，有数学推导证明；
    //     fast = head;
    //     while (fast!=slow)
    //     {
    //         slow = slow->next;
    //         fast = fast->next;
    //     }
    //     return fast;
        
    // }

    ListNode *detectCycle(ListNode *head){

		ListNode *slow = head , *fast = head;

		while(true){
			if(!fast || !fast->next) return nullptr;
			slow = slow->next;
			fast = fast->next->next;

			if(slow==fast){
				break;
			}
		}

		fast = head;
		while(fast!=slow){
			fast = fast->next;
			slow = slow->next;
		}

		return fast;
	}
};
// @lc code=end

