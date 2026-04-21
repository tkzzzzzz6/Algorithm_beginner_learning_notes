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
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        ListNode *index1 = head;
        ListNode *index2 = fast;
        while (index1 != index2) {
          index1 = index1->next;
          index2 = index2->next;
        }
        return index1;
      }
    }
    return NULL;
  }
};
