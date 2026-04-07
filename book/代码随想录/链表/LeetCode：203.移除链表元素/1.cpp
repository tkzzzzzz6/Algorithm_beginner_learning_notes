/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-05 19:10:37
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-06 15:19:08
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
#include <cstdlib>
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    // 删除头节点
    while (head != nullptr &&
           head->val == val) { // 指针类型访问数据应该使用->,不要用.
      ListNode *tmp = head;
      head = head->next;
      delete tmp;
    }
    // 删除非头节点
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};
