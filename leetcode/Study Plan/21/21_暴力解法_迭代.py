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
        # 创建一个哑节点作为合并后链表的起点
        prehead = ListNode(-1)

        # prev指针用于构建新的链表
        prev = prehead 

        # 当两个链表都不为空时，进行合并操作
        while l1 and l2:
            # 比较两个链表当前节点的值
            if l1.val <= l2.val:
                # 如果l1的值小于或等于l2的值，将l1的节点连接到prev
                prev.next = l1
                # 移动l1到下一个节点
                l1 = l1.next 
            else:
                # 如果l2的值小于l1的值，将l2的节点连接到prev
                prev.next = l2
                # 移动l2到下一个节点
                l2 = l2.next 
            # 移动prev到下一个节点
            prev = prev.next

        # 合并后l1和l2最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev.next = l1 if l1 is not None else l2

        # 返回合并后的链表的起点（哑节点的下一个节点）
        return prehead.next