/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 11:23:03
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 11:23:04
 */
/*
* @acwing app=acwing.cn id=85 lang=C++
*
* 28. 在O(1)时间删除链表结点
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// @acwing code end
