/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-22 08:01:54
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-22 08:09:06
 */
/*
* @acwing app=acwing.cn id=34 lang=C++
*
* 36. 合并两个排序的链表
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0);
        auto cur = dummy;

        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }

        if(l1){
            cur->next = l1;
        }else{
            cur->next = l2;
        }

        return dummy->next;
    }
};
// @acwing code end
