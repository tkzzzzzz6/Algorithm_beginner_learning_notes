<!--
 * @Author: tkzzzzzz6
 * @Date: 2026-04-05 19:10:13
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-07 14:04:27
-->

方法 1:分类讨论
头节点:直接
其他节点:该节点的前节点的指针指向该节点后节点

```cpp
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
```

方法 2:添加虚拟头节点(dummy head)
所有节点:该节点的前节点的指针指向该节点后节点

```cpp
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
```

方法 3:递归(效率低)
空节点:直接返回
```cpp
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
```
