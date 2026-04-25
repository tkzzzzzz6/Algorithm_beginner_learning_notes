/*
 * @acwing app=acwing.cn id=89 lang=C++
 *
 * 48. 复杂链表的复刻
 */

// @acwing code start

/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode *copyRandomList(ListNode *head) {
        if (!head)
            return head;

        // 1.在每个原节点后面复制新节点
        auto p = head;
        while (p) {
            auto np = new ListNode(p->val);
            np->next = p->next;
            p->next = np;
            p = np->next;
        }

        // 2.设置新节点的 random 指针
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        // 3.拆分链表
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        p = head;
        while (p) {
            cur->next = p->next;
            cur = cur->next;
            p->next = p->next->next;
            p = p->next;
        }

        return dummy->next;
    }
};

// @acwing code end
