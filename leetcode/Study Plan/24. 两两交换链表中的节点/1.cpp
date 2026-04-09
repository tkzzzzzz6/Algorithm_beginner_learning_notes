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
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0, head); // 声明虚拟节点
    ListNode *cur = dummy;
    while (
        cur->next != NULL &&
        cur->next->next !=
            NULL) { // 每次检查当前节点后面是否至少还有两个节点可以交换,顺序不能交换
      // temp1 记录当前这对中的第一个节点
      ListNode *temp1 = cur->next;
      // temp2 记录下一段链表的起点，避免交换过程中断链
      ListNode *temp2 = cur->next->next->next;
      //   1->2->3 变成 2->1->3
      cur->next = cur->next->next;
      cur->next->next = temp1;
      temp1->next = temp2;
      cur = temp1; // cur 前进到已交换这一对的尾部，继续处理后面的节点
    }
    return dummy->next;
  }
};
