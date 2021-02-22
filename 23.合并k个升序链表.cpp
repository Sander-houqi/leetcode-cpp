/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
//  Definition for singly-linked list.
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
 
// #include<queue>
// #include<vector>
// using namespace std;

//使用优先队列
class Solution{
public:
    struct Comp{   
        //回调函数
        bool operator() (ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
    // 时间复杂度是O(logk*kn)
    // 空间复杂度是O(k),优先队列中的元素不超过k
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        //构建小顶堆
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for(ListNode * list: lists){
            if(list){
                //push头节点
                q.push(list);
            }
        }
        ListNode* dummy = new ListNode(0), *cur = dummy;
        //遍历nk次
        while(!q.empty()){
            //弹出最小的节点
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            //当前链表的下一个节点重新加入小顶堆，每个节点都被插入和删除一次，其复杂度都是logk
            if(cur->next){
                q.push(cur->next);
            }
        }
        return dummy->next;
    }
};

// @lc code=end