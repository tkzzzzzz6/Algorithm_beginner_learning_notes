/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-06 15:04:28
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-06 15:23:03
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy_head = new ListNode(0, head);

    ListNode *cur = dummy_head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else {
        cur = cur->next;
      }
    }
    head = dummy_head->next;
    delete dummy_head;
    return head;
  }
};
