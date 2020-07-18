# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        q = [root]
        last = q
        while q:
            level = [n for node in q if node for n in [node.left, node.right] if n]
            q = level
            if level:
                last = level
        
        return last[0].val
        
