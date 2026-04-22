/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-21 22:02:20
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-21 22:04:31
 */
/*
* @acwing app=acwing.cn id=33 lang=C++
*
* 35. 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        auto a = head,b = head->next;

        while(b){
            auto t = b->next;
            b->next = a;
            a = b,b = t;
        }

        head->next = nullptr;

        return a;
    }
};
// @acwing code end
