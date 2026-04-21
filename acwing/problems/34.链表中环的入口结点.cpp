/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-21 21:19:52
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-21 21:29:08
 */
/*
* @acwing app=acwing.cn id=86 lang=C++
*
* 34. 链表中环的入口结点
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
    ListNode *entryNodeOfLoop(ListNode *head) {
        if(!head || !head->next)return nullptr;

        auto slow = head,fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }

        if(!fast || !fast->next)return nullptr;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};
// @acwing code end
