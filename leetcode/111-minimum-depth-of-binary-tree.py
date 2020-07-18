# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        l = self.minDepth(root.left)
        r = self.minDepth(root.right)
        
        return min(l, r) + 1 if l and r else max(l, r) + 1
