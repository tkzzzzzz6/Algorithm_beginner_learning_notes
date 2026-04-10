from typing import Optional

# 定义链表节点类
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val  # 节点的值
        self.next = next  # 指向下一个节点的指针

# 定义解决方案类
class Solution:
    # 合并两个有序链表的函数
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # 如果l1为空，直接返回l2
        if l1 is None:
            return l2
        # 如果l2为空，直接返回l1
        elif l2 is None:
            return l1
        # 如果l1的值小于l2的值
        elif l1.val < l2.val:
            # 递归合并l1的下一个节点和l2，并将结果赋值给l1的下一个节点
            l1.next = self.mergeTwoLists(l1.next, l2)
            # 返回l1作为合并后的链表的头节点
            return l1
        else:
            # 递归合并l1和l2的下一个节点，并将结果赋值给l2的下一个节点
            l2.next = self.mergeTwoLists(l1, l2.next)
            # 返回l2作为合并后的链表的头节点
            return l2