/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 12:06:48
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 12:06:50
 */
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

        auto cur = dummy;
        while(cur->next && cur->next->next){
            int val = cur->next->val;
            if(cur->next->next->val == val){
                while(cur->next && cur->next->val == val)
                    cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @acwing code end
