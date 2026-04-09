// 递归法求解
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
  ListNode *reverseList(ListNode *head) { return reverse(head, NULL); }
  ListNode *reverse(ListNode *cur, ListNode *pre) {
    if (cur == NULL)
      return pre;
    ListNode *temp = cur->next;
    cur->next = pre;
    return reverse(temp, cur);
  }
};
