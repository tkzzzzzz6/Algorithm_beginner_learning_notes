/*
* @acwing app=acwing.cn id=27 lang=C++
*
* 29. 删除链表中重复的节点
*/

// @acwing code start

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
    ListNode* deleteDuplication(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto p = dummy;
        while(p->next){
            auto q = p->next;
            while(q && p->next->val == q->val)q = q->next;
            if(p->next->next == q)p = p->next;
            else p->next = q;
        }
        return dummy->next;
    }
};
// @acwing code end
