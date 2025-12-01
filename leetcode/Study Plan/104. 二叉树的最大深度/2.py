# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        cnt = 0
        def dfs(node,depth):
            if node is None:
                return
            depth+=1
            nonlocal cnt
            cnt = max(cnt,depth)
            dfs(node.left,depth)
            dfs(node.right,depth)
        dfs(root,0)
        return cnt
