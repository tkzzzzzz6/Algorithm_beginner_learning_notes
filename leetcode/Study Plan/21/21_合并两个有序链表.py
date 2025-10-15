# 定义单链表的节点类（注释掉的代码）
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 定义解决方案类
class Solution:
    # 定义合并两个有序链表的方法
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # 创建一个哑节点作为合并后链表的起点
        dummy = ListNode()
        # 当前节点指向哑节点
        current = dummy

        # 当两个链表都不为空时，进行合并操作
        while list1 and list2:
            # 比较两个链表当前节点的值
            if list1.val < list2.val:
                # 如果list1的值小于list2的值，将list1的节点连接到当前节点
                current.next = list1
                # 移动list1到下一个节点
                list1 = list1.next
            else:
                # 如果list2的值小于或等于list1的值，将list2的节点连接到当前节点
                current.next = list2
                # 移动list2到下一个节点
                list2 = list2.next
            # 移动当前节点到下一个节点
            current = current.next

        # 如果list1还有剩余节点，将其连接到当前节点
        if list1:
            current.next = list1
        # 如果list2还有剩余节点，将其连接到当前节点
        elif list2:
            current.next = list2
        
        # 返回合并后的链表的起点（哑节点的下一个节点）
        return dummy.next