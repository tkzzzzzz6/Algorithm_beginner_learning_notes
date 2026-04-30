/*
 * @acwing app=acwing.cn id=62 lang=C++
 *
 * 66.
 * 两个链表的第一个公共结点
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
  ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
    auto p1 = headA, p2 = headB;
    while (p1 != p2) {
      if (!p1)
        p1 = headB; //需要交叉走,这样两个指针完整遍历以后两个指针走的路程是相同的,才有可能相遇
      else
        p1 = p1->next;
      if (!p2)
        p2 = headA;
      else
        p2 = p2->next;
    }
    return p1;
  }
};
// @acwing code end
