# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.balanced = True
        
    def depth(self, root):
        if root is None or not self.balanced:
            return 0
        l = self.depth(root.left)
        r = self.depth(root.right)
        if abs(l-r) > 1:
            self.balanced = False
        return 1 + max(l, r)
    
    def isBalanced(self, root: TreeNode) -> bool:
        self.depth(root)
        return self.balanced
