/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-21 18:45:16
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-21 18:47:00
 */
/*
* @acwing app=acwing.cn id=32 lang=C++
*
* 33. 链表中倒数第k个节点
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
    ListNode* findKthToTail(ListNode* head, int k) {
        auto fast = head,slow = head;

        while(k--){
            if(fast == nullptr)return nullptr;
            fast = fast->next;
        }

        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @acwing code end
