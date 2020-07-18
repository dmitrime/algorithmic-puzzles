# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def compare(self, a, b):
        if a and b and a.val == b.val:
            return self.compare(a.left, b.right) and self.compare(a.right, b.left)
        return a == b
        
    def isSymmetric(self, root: TreeNode) -> bool:
        if root:
            return self.compare(root.left, root.right)
        return True
