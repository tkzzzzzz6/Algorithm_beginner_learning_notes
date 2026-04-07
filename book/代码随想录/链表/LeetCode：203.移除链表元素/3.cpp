/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-06 15:27:59
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-06 15:39:38
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
    if (head == nullptr) {
      return nullptr;
    }
    // 递归处理
    if (head->val == val) {
      ListNode *tmp = head;
      head = removeElements(head->next, val);
      delete tmp;
      return head;
    } else {
      head->next = removeElements(head->next, val);
      return head;
    }
  }
};
